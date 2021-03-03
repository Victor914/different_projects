#ifndef RAISING_POWER_H
#define RAISING_POWER_H
#include "34_binary.h"
#include <cmath>
#include "add_function.h"

class raising_power : public binary
{
    const std::string ident = "raising_power", cap = "^";
public:
    raising_power();
    double get_value();
    std::string get_cap();
    std::string get_id();
    std::string get_name();
    void action(std::list<double>&);
    void to_stack(std::list<std::shared_ptr<formula>>&,
                  std::list<std::shared_ptr<formula>>&, size_t &);
};

#endif // RAISING_POWER_H
