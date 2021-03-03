#ifndef MINUS_H
#define MINUS_H
#include "33_unary.h"
#include "add_function.h"

class minus : public unary
{
    const std::string ident = "minus", cap = "-";
public:
    minus();
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // MINUS_H
