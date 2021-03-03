#include "35_left.h"



left::left()
{

}

double left::get_value()
{
    return 0.0;
}

std::string left::get_cap()
{
    return this->cap;
}

std::string left::get_id()
{
    return this->ident;
}

std::string left::get_name()
{
    return "";
}

void left::action(std::list<double> &)
{
    return;
}

void left::to_stack(std::list<std::shared_ptr<formula> > &,
                    std::list<std::shared_ptr<formula> > & buff, size_t & i)
{
    buff.push_back(std::make_shared<left>(*this));
    ++i;
    return;
}


