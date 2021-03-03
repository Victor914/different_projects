#ifndef TO_VECTOR_H
#define TO_VECTOR_H
//#include <string>
#include <vector>
#include <memory>
#include <map>
#include "1_formula.h"

#include "31_variable.h"
#include "32_constant.h"
#include "35_left.h"
#include "36_right.h"
#include "41_minus.h"
#include "42_plus.h"
#include "43_division.h"
#include "44_multiplication.h"
#include "45_subtraction.h"
#include "46_addition.h"
#include "47_raising_power.h"

//using namespace std;

class to_vector
{
    std::string str, substr;
    std::string::size_type i, size;
    bool operand, operation;
    std::map<double, std::shared_ptr<constant> > cart_num;
    std::vector<std::shared_ptr<formula>> vec;

    bool check_br_right();
    bool check_br_left();
    bool check_var();
    bool check_num();
    bool check_un();
    bool check_bin();

    bool pars_var();
    bool pars_num();

public:
    to_vector(std::string);
    ~to_vector();
    bool get_vector(std::vector<std::shared_ptr<formula> > &,
                    std::map<std::string, std::shared_ptr<variable> > &);

};

#endif // TO_VECTOR_H
