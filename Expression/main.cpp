#include <iostream>
#include <vector>
#include <map>
#include "1_formula.h"
#include <memory>
#include "add_function.h"
#include "to_vector.h"
#include <list>

using namespace std;


int main()
{
    char f('Y');
    bool fl(1);    
    while (f == 'y' || f == 'Y') {
        try {
            cin.clear();
            string stroka = "";
            if (!fl) cin.get(); else fl = 0;
            cout << "Enter an expression: ";
            getline(cin, stroka, '\n');



            vector<shared_ptr<formula>> expression;
            std::map<std::string, std::shared_ptr<variable> > map_var;


            //Создаём вектор по строке
            to_vector t_v(stroka);
            t_v.get_vector(expression, map_var);

            add_function f;
//            //Выводим получившийся вектор
//            f.show_vector(expression);

            //Присваиваем значения переменным
            try {
                for (auto i = map_var.begin(); i != map_var.end(); ++i) {
                    double k;
                    cout << i->first << " = ";
                    cin >> k;
                    i->second->set_value(k);
                }
            } catch (exception) {
                throw std::string("not a number");
            }

            //Создаём очередь опереций
            list<shared_ptr<formula>> buff;
            list<shared_ptr<formula>> stck;
            size_t i = 0;
            while (i < expression.size()) {
                expression[i]->to_stack(stck, buff, i);
            }
            while (!buff.empty()) {
                add_function f;
                int pr = f.priority(buff.back()->get_id(), "&");
                if (pr == 2) {
                    stck.push_back(buff.back());
                    buff.pop_back();
                } else
                    throw std::string("( - incorrect location");
            }

//            //Смотрим значения всех объектов
//            for (auto i = expression.begin(); i != expression.end(); ++i)
//                std::cout << (*i)->get_value() << " ";
//            cout << endl;
//            //Смотрим на значения переменных в map
//            for (auto i = map_var.begin(); i != map_var.end(); ++i)
//                std::cout << i->second.use_count() << " ";
//            cout << endl;

            //Выводим получившийся стек
            f.show_stack(stck);

            list<double> buff_calculate;
            while (!stck.empty()) {
                stck.front()->action(buff_calculate);
                stck.pop_front();
//                //Смотрим значения буфера вычислений
//                f.show_calculate(buff_calculate);
            }
            cout << "Result: " << buff_calculate.back() << endl;
        } catch(string str) {
            cerr << "Error: " << str << endl;
        }

        cout << "Continue? (Y/N)" << endl;
        cin >> f;

    }
    return 0;
}
