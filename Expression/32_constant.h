#ifndef CONSTANT_H
#define CONSTANT_H
#include "21_operand.h"

class constant : public operand
{
    const std::string ident = "constant";
    double value;
public:
    constant(double val);
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // CONSTANT_H
