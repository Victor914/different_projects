#ifndef ADDITION_H
#define ADDITION_H
#include "34_binary.h"
#include "add_function.h"

class addition : public binary
{
    const std::string ident = "addition", cap = "+";
public:
    addition();
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // ADDITION_H
