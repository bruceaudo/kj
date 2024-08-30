#include "../headers/Math.h"
#include "../headers/Math_operations.h"
#include <stdexcept>
#include <iostream>

// Define static members
double Math::num1 = 0.0;
double Math::num2 = 0.0;
Math_operations Math::operation = Math_operations::ADD;

Math::Math(double num1, double num2, Math_operations op) {}

double Math::add(double num1, double num2)
{
    return num1 + num2;
}
double Math::sub(double num1, double num2)
{
    return num1 - num2;
}
double Math::mul(double num1, double num2)
{
    return num1 * num2;
}
double Math::div(double num1, double num2)
{
    try
    {
        if (num2 == 0)
        {
            throw std::runtime_error("Error: Cannot divide by 0.");
        }
        return num1 / num2;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}