#include "31_variable.h"



variable::variable(double val, std::string name)
{
    this->name = name;
    this->value = val;
}

void variable::set_value(double b)
{
    this->value = b;
}

std::string variable::get_name()
{
    return this->name;
}

double variable::get_value()
{
    return this->value;
}

std::string variable::get_cap()
{
    return this->name;
}

std::string variable::get_id()
{
    return this->ident;
}

void variable::action(std::list<double> &buff)
{
    buff.push_back(this->value);
    return;
}

void variable::to_stack(std::list<std::shared_ptr<formula> > & st,
                        std::list<std::shared_ptr<formula> > &, size_t & i)
{
    st.push_back(std::make_shared<variable>(*this));
    ++i;
    return;
}
