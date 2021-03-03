#include "47_raising_power.h"


raising_power::raising_power()
{

}

double raising_power::get_value()
{
    return 0.0;
}

std::string raising_power::get_cap()
{
    return this->cap;
}

std::string raising_power::get_id()
{
    return this->ident;
}

std::string raising_power::get_name()
{
    return "";
}

void raising_power::action(std::list<double> &buff)
{
    if (buff.empty())
        throw std::string("not enough operands");
    double b1 = buff.back();
    buff.pop_back();
    if (buff.empty())
        throw std::string("not enough operands");
    double b2 = buff.back();
    buff.pop_back();
    buff.push_back(pow(b2, b1));
}

void raising_power::to_stack(std::list<std::shared_ptr<formula> > & st,
                    std::list<std::shared_ptr<formula> > & buff, size_t & i)
{
    if (buff.empty()) {
        buff.push_back(std::make_shared<raising_power>(*this));
        ++i;
    } else {
        add_function f;
        int pr = f.priority(buff.back()->get_id(), this->get_id());
        if (pr == 2) {
            st.push_back(buff.back());
            buff.pop_back();
        } else {
            buff.push_back(std::make_shared<raising_power>(*this));
            ++i;
        }
    }
    return;
}
