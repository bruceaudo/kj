#ifndef MATH_H // Include guard to prevent multiple inclusions
#define MATH_H

#include <string>
#include "../headers/Math_operations.h"

class Math
{
public:
    // Constructor
    Math(double num1, double num2, Math_operations op);

    // Method declarations
    static double add(double num1, double num2);
    static double sub(double num1, double num2);
    static double mul(double num1, double num2);
    static double div(double num1, double num2);

private:
    // Member variables
    static double num1;
    static double num2;
    static Math_operations operation;
};

#endif // MATH_H