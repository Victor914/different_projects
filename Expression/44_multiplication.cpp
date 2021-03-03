#include "44_multiplication.h"

multiplication::multiplication()
{

}

double multiplication::get_value()
{
    return 0.0;
}

std::string multiplication::get_cap()
{
    return this->cap;
}

std::string multiplication::get_id()
{
    return this->ident;
}

std::string multiplication::get_name()
{
    return "";
}

void multiplication::action(std::list<double> &buff)
{
    if (buff.empty())
        throw std::string("not enough operands");
    double b1 = buff.back();
    buff.pop_back();
    if (buff.empty())
        throw std::string("not enough operands");
    double b2 = buff.back();
    buff.pop_back();
    buff.push_back(b2 * b1);

}

void multiplication::to_stack(std::list<std::shared_ptr<formula> > & st,
                    std::list<std::shared_ptr<formula> > & buff, size_t & i)
{
    if (buff.empty()) {
        buff.push_back(std::make_shared<multiplication>(*this));
        ++i;
    } else {
        add_function f;
        int pr = f.priority(buff.back()->get_id(), this->get_id());
        if (pr == 2) {
            st.push_back(buff.back());
            buff.pop_back();
        } else {
            buff.push_back(std::make_shared<multiplication>(*this));
            ++i;
        }
    }
    return;
}




