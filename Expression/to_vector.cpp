#include "to_vector.h"



to_vector::to_vector(std::string str1) {
    this->str = "";
    this->i = 0;
    this->substr = "";
    this->operation = 0;
    this->operand = 0;
    for (auto i = str1.begin(); i != str1.end(); ++i)
        if (*i != ' ') this->str += *i;
    this->size = this->str.size();
}

to_vector::~to_vector()
{
    return;
}

bool to_vector::get_vector(std::vector<std::shared_ptr<formula> > & vect,
                           std::map<std::string, std::shared_ptr<variable> > & cart_var)
{
    auto ptr_plus = std::make_shared<plus>();
    auto ptr_minus = std::make_shared<minus>();
    auto ptr_addition = std::make_shared<addition>();
    auto ptr_subtraction = std::make_shared<subtraction>();
    auto ptr_multiplication = std::make_shared<multiplication>();
    auto ptr_division = std::make_shared<division>();
    auto ptr_raising_power = std::make_shared<raising_power>();
    auto ptr_left = std::make_shared<left>();
    auto ptr_right = std::make_shared<right>();
    while (i < size) {
        if (this->check_un()) {
            if (this->substr == "+") {
                vect.push_back(ptr_plus);
            } else {
                vect.push_back(ptr_minus);
            }
        } else if (this->check_bin()) {
            if (this->substr == "+") {
                vect.push_back(ptr_addition);
            } else if (this->substr == "-") {
                vect.push_back(ptr_subtraction);
            } else if (this->substr == "*") {
                vect.push_back(ptr_multiplication);
            } else if (this->substr == "/") {
                vect.push_back(ptr_division);
            } else {
                vect.push_back(ptr_raising_power);
            }
        } else if (this->check_num()) {
            double b(0);
            try {
                b = std::stod(this->substr);
            } catch(std::exception) {
                throw substr;
            }
            auto it = this->cart_num.find(b);
            if (it != cart_num.end()) {
                auto ptr = it->second;
                vect.push_back(ptr);
            } else {
                constant el(b);
                auto ptr_el = std::make_shared<constant>(el);
                cart_num[b] = ptr_el;
                vect.push_back(ptr_el);
            }
        } else if (this->check_var()) {
            auto it = cart_var.find(this->substr);
            if (it != cart_var.end()) {
                auto ptr = it->second;
                vect.push_back(ptr);
            } else {
                variable el(0, substr);
                auto ptr_el = std::make_shared<variable>(el);
                cart_var[substr] = ptr_el;
                vect.push_back(ptr_el);
            }
        } else if (this->check_br_left()) {
            vect.push_back(ptr_left);
        } else if (this->check_br_right()) {
            vect.push_back(ptr_right);
        } else
            throw str.substr(i, 1) + " - invalid character";
    }
    return 1;
}

bool to_vector::check_br_left() {
    if (str[i] == '(') {
        if ( (i == 0)||(this->operation)||(str[i] == '(') ) {
            if (i != this->size - 1) {
                this->operation = 0;
                this->substr = str[i];
                ++(this->i);
                return 1;
            } else
                throw str.substr(i, 1) + " - incorrect location";
        } else
            throw str.substr(i, 1) + " - incorrect location";
    } else
        return 0;
}

bool to_vector::check_br_right() {
    if (str[i] == ')') {
        if ( (this->operand)||(str[i] == ')') ) {
            this->operand = 0;
            this->substr = str[i];
            ++(this->i);
            return 1;
        } else
            throw str.substr(i, 1) + " - incorrect location";
    } else
        return 0;

}

bool to_vector::check_var() {
    if ( ((str[i] >= 'A')&&(str[i] <= 'Z')) || ((str[i] >= 'a')&&(str[i] <= 'z')) ) {
        if ( (i == 0)||(this->operation)||(str[i-1] == '(') ) {
            this->substr = str[i];
            if (pars_var()) {
                this->operation = 0;
                this->operand = 1;
                return 1;
            } else
                throw std::string("invalid variable name");
        } else
            throw str.substr(i, 1) + " - incorrect location";
    } else
        return 0;
}

bool to_vector::check_num() {
    if ( (str[i] >= '0')&&(str[i] <= '9') ) {
        if ( (i == 0)||(this->operation)||(str[i-1] == '(') ) {
            this->substr = str[i];
            if (pars_num()) {
                this->operation = 0;
                this->operand = 1;
                return 1;
            } else
                throw std::string("not a number");
        } else
            throw str.substr(i, 1) + " - incorrect location";
    } else
        return 0;
}

bool to_vector::check_un() {
    if ( (str[i] == '+')||(str[i] == '-') ) {
        if ( (i == 0)||(str[i - 1] == '(')) {
            if  (i != this->size - 1) {
                this->operation = 1;
                this->substr = str[i];
                ++(this->i);
                return 1;
            } else
                throw str.substr(i, 1) + " - incorrect location";
        } else
            return 0;
    } else
        return 0;
}

bool to_vector::check_bin() {
    if ( (str[i] == '+')||(str[i] == '-')||(str[i] == '*')||(str[i] == '/')||(str[i] == '^') ) {
        if ( (this->operand)||(str[i - 1] == ')') ) {
            if (i != this->size - 1) {
                this->operand = 0;
                this->operation = 1;
                this->substr = str[i];
                ++(this->i);
                return 1;
            } else
                throw str.substr(i, 1) + " - incorrect location";
        } else
            throw str.substr(i, 1) + " - incorrect location";
    } else
        return 0;
}

bool to_vector::pars_var()
{
    ++(this->i);
    while ( (i < this->size) && (((str[i] >= 'A')&&(str[i] <= 'Z')) || ((str[i] >= 'a')&&(str[i] <= 'z')))  ) {
        this->substr += str[i];
        ++(this->i);
    }
    if ( i == this->size ) return 1;
    if ( (str[i] == '+')||(str[i] == '-')||(str[i] == '*')||(str[i] == '/')||(str[i] == '^')||(str[i] == ')') )
        return 1;
    else
        return 0;
}

bool to_vector::pars_num()
{
    bool f(1);
    ++(this->i);
    while ( (i < this->size) && (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.') && f) ) {
        if (str[i] == '.') f = 0;
        this->substr += str[i];
        ++(this->i);
    }
    if ( i == this->size ) return 1;
    if ( (str[i] == '+')||(str[i] == '-')||(str[i] == '*')||(str[i] == '/')||(str[i] == '^')||(str[i] == ')') )
        return 1;
    else
        return 0;
}
