#include "add_function.h"


add_function::add_function()
{
    size_t n = 8;
    this->prior.resize(n);
    //Таблица приоритетов
    this->prior[0] = {4, 1, 1, 1, 1, 1, 1, 1, 5};
    this->prior[1] = {2, 2, 2, 1, 1, 1, 1, 1, 2};
    this->prior[2] = {2, 2, 2, 1, 1, 1, 1, 1, 2};
    this->prior[3] = {2, 2, 2, 2 ,2, 1, 1, 1, 2};
    this->prior[4] = {2, 2, 2, 2, 2, 1, 1, 1, 2};
    this->prior[5] = {2, 2, 2, 2, 2, 2, 1, 1, 2};
    this->prior[6] = {2, 2, 2, 2, 2, 2, 2, 1, 2};
    this->prior[7] = {5, 1, 1, 1, 1, 1, 1, 1, 3};
    //Таблица соответствия
    this->sootv["&"] = 0;
    this->sootv["subtraction"] = 1;
    this->sootv["addition"] = 2;
    this->sootv["multiplication"] = 3;
    this->sootv["division"] = 4;
    this->sootv["minus"] = 5;
    this->sootv["raising_power"] = 6;
    this->sootv["left"] = 7;
    this->sootv["right"] = 8;
}
//Возвращение приоритета по идентификаторам
int add_function::priority(std::string buf, std::string vec)
{
    return this->prior[this->sootv.find(buf)->second][this->sootv.find(vec)->second];
}

void add_function::show_vector(std::vector<std::shared_ptr<formula> > a)
{
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << i << " " << a[i]->get_id() << std::endl;
    }
}

void add_function::show_stack(std::list<std::shared_ptr<formula> > st)
{
   std::cout << "Reverse Polish notation: " << std::endl;
    for (auto i = st.begin(); i != st.end(); ++i)
        std::cout << (*i)->get_cap() << " ";
    std::cout << std::endl;
}

void add_function::show_calculate(std::list<double> b_calc)
{
    std::cout << "//////" << std::endl;
    for (auto i = b_calc.begin(); i != b_calc.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl << "\\\\\\\\\\\\" << std::endl;

}
