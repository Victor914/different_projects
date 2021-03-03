TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    to_vector.cpp \
    1_formula.cpp \
    21_operand.cpp \
    22_operation.cpp \
    23_bracket.cpp \
    31_variable.cpp \
    32_constant.cpp \
    33_unary.cpp \
    34_binary.cpp \
    35_left.cpp \
    36_right.cpp \
    41_minus.cpp \
    42_plus.cpp \
    43_division.cpp \
    44_multiplication.cpp \
    45_subtraction.cpp \
    46_addition.cpp \
    47_raising_power.cpp \
    add_function.cpp

HEADERS += \
    to_vector.h \
    1_formula.h \
    21_operand.h \
    22_operation.h \
    23_bracket.h \
    31_variable.h \
    32_constant.h \
    33_unary.h \
    34_binary.h \
    35_left.h \
    36_right.h \
    41_minus.h \
    42_plus.h \
    43_division.h \
    44_multiplication.h \
    46_addition.h \
    45_subtraction.h \
    47_raising_power.h \
    add_function.h

DISTFILES += \
    priority.txt \
    sootv.txt
