#include <bits/stdc++.h>
using namespace std;

class Calculator
{
public:
    double op1;
    double op2;

    Calculator() : op1(0), op2(0) {}

    double add() { return op1 + op2; }

    double sub() { return op1 - op2; }

    double mul() { return op1 * op2; }

    double div() { return (op2 != 0) ? op1 / op2 : (exit(1), 0.0); }
};

int main(int argc, char *argv[])
{
    while (1)
    {
        Calculator calc;
        char op;

        if (argc == 4)
        {
            calc.op1 = atof(argv[1]);
            calc.op2 = atof(argv[3]);
            op = *argv[2];
        }
        else
        {
            system("cls");
            cout << "-----------Calculator-----------\n";
            cout << "(+) Enter an expression -> ";

            if (!(std::cin >> calc.op1 >> op >> calc.op2))
            {
                cout << "\n(-) Error\n";
                return 1;
            }
        }

        double result;

        switch (op)
        {
        case '+':
            result = calc.add();
            break;
        case '-':
            result = calc.sub();
            break;
        case '*':
            result = calc.mul();
            break;
        case '/':
            result = calc.div();
            break;
        default:
            cout << "\n(-) Invalid operator\n";
            return 1;
        }

        cout << "\n(+) Result -> " << result << "\n";
        system("pause");
    }
    return 0;
}