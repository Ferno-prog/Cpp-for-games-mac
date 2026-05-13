#include <iostream>

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getNumber()
{
    double num;

    std::cout << "Please enter a number: ";
    std::cin >> num;

    while (std::cin.fail())
    {
        clearInput();

        std::cerr << "ERROR: Expected a number." << std::endl;
        std::cout << "Please enter a number: ";
        std::cin >> num;
    }

    return num;
}

char getOp()
{
    char op;
    std::cout << "Please enter an operator: ";
    std::cin >> op;

    while (op != '+' && op != '-' && op != '*' && op != '/')
    {
        clearInput();

        std::cerr << "Expected an operator." << std::endl;
        std::cout << "Please enter an operator: ";
        std::cin >> op;
    }

    return op;
}

double getResult(double lhs, char op, double rhs)
{
    double result;
    switch (op)
  {
    case '+':
        result = lhs + rhs;
        break;
    case '-':
       result = lhs - rhs;
        break;
    case '*':
        result = lhs - rhs;
        break;
    case '/':
        result = lhs - rhs;
        break;
    default:
        std::cerr << "ERROR: Invalid operator: " << op;
        break;
  }

  return result;
}



int main()
{
    double lhs = getNumber();
    char op = getOp();
    double rhs = getNumber();

    while (op == '/' && rhs == 0.0f)
    {
        std::cerr << "ERROR: Cannot devide by 0." << std::endl;
        rhs = getNumber();
    }

    double result = getResult(lhs, op, rhs);
    std::cout << "Result: " << result << std::endl;
    
    clearInput();
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.get();

    return 0;
}