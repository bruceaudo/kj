#include <iostream>
#include <stdexcept>
#include <string> // For std::stod
#include "headers/Math_operations.h"
#include "headers/Math.h"

/*
    usage:
    addition example: program_name 12 5 -A
    subtraction example: program_name 12 5 -S
    multiplication example: program_name 12 5 -M
    division example: program_name 12 5 -D
*/

Math_operations operation;

double performOperation(double num1, double num2);

int main(int argc, char *argv[])
{
    try
    {
        // Check for correct number of arguments
        if (argc < 4)
        {
            throw std::runtime_error("Error: You must include two operands and an operation.");
        }

        // Convert operands to double
        double op1 = std::stod(argv[1]);
        double op2 = std::stod(argv[2]);

        // Determine the operation based on user input
        std::string op_flag = argv[3];

        if (op_flag == "-A")
        {
            operation = Math_operations::ADD;
        }
        else if (op_flag == "-S")
        {
            operation = Math_operations::SUB;
        }
        else if (op_flag == "-M")
        {
            operation = Math_operations::MUL;
        }
        else if (op_flag == "-D")
        {
            operation = Math_operations::DIV;
        }
        else
        {
            throw std::runtime_error("Error: Invalid operation.");
        }

        // Perform the chosen operation
        std::cout << "> " << performOperation(op1, op2) << std::endl;

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

// Function to perform the operation based on the chosen Math_operations enum
double performOperation(double num1, double num2)
{
    switch (operation)
    {
    case Math_operations::ADD:
        return Math::add(num1, num2);
    case Math_operations::SUB:
        return Math::sub(num1, num2);
    case Math_operations::MUL:
        return Math::mul(num1, num2);
    case Math_operations::DIV:
        if (num2 == 0) // Ensure division by zero is handled
        {
            throw std::runtime_error("Error: Cannot divide by 0.");
        }
        return Math::div(num1, num2);

    default:
        throw std::runtime_error("Error: Operation not allowed.");
    }
}
