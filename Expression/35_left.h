#ifndef LEFT_H
#define LEFT_H
#include "23_bracket.h"


class left : public bracket
{
    const std::string ident = "left", cap = "(";
public:
    left();
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // LEFT_H
