#include "43_division.h"

division::division()
{

}

double division::get_value()
{
    return 0.0;
}

std::string division::get_cap()
{
    return this->cap;
}

std::string division::get_id()
{
    return this->ident;
}

std::string division::get_name()
{
    return "";
}

void division::action(std::list<double> &buff)
{
    if (buff.empty())
        throw std::string("not enough operands");
    double b1 = buff.back();
    buff.pop_back();
    if (buff.empty())
        throw std::string("not enough operands");
    double b2 = buff.back();
    buff.pop_back();

    if (b1 != 0.0)
        buff.push_back(b2 / b1);
    else
        throw std::string("division by zero");

}

void division::to_stack(std::list<std::shared_ptr<formula> > & st,
                        std::list<std::shared_ptr<formula> > & buff, size_t & i)
{
    if (buff.empty()) {
        buff.push_back(std::make_shared<division>(*this));
        ++i;
    } else {
        add_function f;
        int pr = f.priority(buff.back()->get_id(), this->get_id());
        if (pr == 2) {
            st.push_back(buff.back());
            buff.pop_back();
        } else {
            buff.push_back(std::make_shared<division>(*this));
            ++i;
        }
    }
    return;
}

