#include "41_minus.h"

minus::minus()
{

}

double minus::get_value()
{
    return 0.0;
}

std::string minus::get_cap()
{
    return this->cap;
}

std::string minus::get_id()
{
    return this->ident;
}

std::string minus::get_name()
{
    return "";
}

void minus::action(std::list<double> &buff)
{
    if (buff.empty())
        throw std::string("not enough operands");
    double b = -buff.back();
    buff.pop_back();
    buff.push_back(b);
    return;
}

void minus::to_stack(std::list<std::shared_ptr<formula> > & st,
                    std::list<std::shared_ptr<formula> > & buff, size_t & i)
{
    if (buff.empty()) {
        buff.push_back(std::make_shared<minus>(*this));
        ++i;
    } else {
        add_function f;
        int pr = f.priority(buff.back()->get_id(), this->get_id());
        if (pr == 2) {
            st.push_back(buff.back());
            buff.pop_back();
        } else {
            buff.push_back(std::make_shared<minus>(*this));
            ++i;
        }
    }
    return;
}

