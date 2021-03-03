#include "36_right.h"

right::right()
{

}

double right::get_value()
{
    return 0.0;
}

std::string right::get_cap()
{
    return this->cap;
}

std::string right::get_id()
{
    return this->ident;
}

std::string right::get_name()
{
    return "";
}

void right::action(std::list<double> &)
{
    return;
}

void right::to_stack(std::list<std::shared_ptr<formula> > & st,
                    std::list<std::shared_ptr<formula> > & buff, size_t & i)
{
    if (buff.empty())
        throw std::string(") - incorrect location");
    add_function f;
    int pr = f.priority(buff.back()->get_id(), this->get_id());
    if (pr == 2) {
        st.push_back(buff.back());
        buff.pop_back();
    } else {
        buff.pop_back();
        ++i;
    }
}
