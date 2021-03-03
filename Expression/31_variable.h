#ifndef VARIABLE_H
#define VARIABLE_H
#include "21_operand.h"
#include <memory>

class variable : public operand
{
    const std::string ident = "variable";
    std::string name;
    double value;
public:
    variable(double val, std::string name);
    void set_value(double);
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula> > &,
                  std::list<std::shared_ptr<formula> > &, size_t &);
};

#endif // VARIABLE_H
