#ifndef FORMULA_H
#define FORMULA_H
#include <list>
#include <memory>


class formula
{
public:
    formula();
    virtual ~formula();
    virtual void action(std::list<double>&) = 0;
    virtual double get_value() = 0;
    virtual std::string get_cap() = 0;
    virtual std::string get_name() = 0;
    virtual std::string get_id() = 0;
    virtual void to_stack(std::list<std::shared_ptr<formula>>&,
                          std::list<std::shared_ptr<formula>>&, size_t &) = 0;
};


#endif // FORMULA_H
