#ifndef RIGHT_H
#define RIGHT_H
#include "23_bracket.h"
#include "add_function.h"

class right : public bracket
{
    const std::string ident = "right", cap = ")";
public:
    right();
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // RIGHT_H
