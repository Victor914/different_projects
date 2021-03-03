#ifndef ADD_FUNCTION_H
#define ADD_FUNCTION_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include "1_formula.h"

class add_function
{
    std::vector<std::vector <int>> prior;
    std::map<std::string, size_t> sootv;
public:
    add_function();
    int priority(std::string buf, std::string vec);
    void show_vector(std::vector<std::shared_ptr<formula> >);
    void show_stack(std::list<std::shared_ptr<formula> >);
    void show_calculate(std::list<double>);
};

#endif // ADD_FUNCTION_H
