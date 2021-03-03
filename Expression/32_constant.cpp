#include "32_constant.h"



constant::constant(double val)
{
    this->value = val;
}

double constant::get_value()
{
    return this->value;
}

std::string constant::get_cap()
{
    return std::to_string(this->value);
}

std::string constant::get_id()
{
    return this->ident;
}

std::string constant::get_name()
{
    return "";
}

void constant::action(std::list<double> &buff)
{
    buff.push_back(this->value);
    return;
}

void constant::to_stack(std::list<std::shared_ptr<formula> > & st,
                        std::list<std::shared_ptr<formula> > &, size_t & i)
{
    st.push_back(std::make_shared<constant>(*this));
    ++i;
    return;
}
