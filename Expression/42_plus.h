#ifndef PLUS_H
#define PLUS_H
#include "33_unary.h"

class plus : public unary
{
    const std::string ident = "plus", cap = "+";
public:
    plus();
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // PLUS_H
