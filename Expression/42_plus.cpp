#include "42_plus.h"


plus::plus()
{

}

double plus::get_value()
{
    return 0.0;
}

std::string plus::get_cap()
{
    return this->cap;
}

std::string plus::get_id()
{
    return this->ident;
}

std::string plus::get_name()
{
    return "";
}

void plus::action(std::list<double> &)
{
    return;
}

void plus::to_stack(std::list<std::shared_ptr<formula> > &,
                    std::list<std::shared_ptr<formula> > &, size_t &i)
{
    ++i;
    return;
}
