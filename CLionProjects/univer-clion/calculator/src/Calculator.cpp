#include "Calculator.h"

// Конструктор
Calculator::Calculator() {
    commands["+"] = new AddCommand();
    commands["-"] = new SubtractCommand();
    commands["*"] = new MultiplyCommand();
    commands["/"] = new DivideCommand();
    commands["%"] = new ModulusCommand();
    commands["^"] = new PowerCommand();
}

// Метод для вычисления
double Calculator::calculate(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    Stack<double> stack;

    while (iss >> token) {
        if (commands.find(token) != commands.end()) {
            if (stack.isEmpty()) {
                throw std::out_of_range("Стек пуст, нельзя выполнить операцию.");
            }
            double b = stack.top(); stack.pop();
            if (stack.isEmpty()) {
                throw std::out_of_range("Стек пуст, нельзя выполнить операцию.");
            }
            double a = stack.top(); stack.pop();
            double result = commands[token]->execute(a, b);
            stack.push(result);
        } else {
            if (token == "sqrt" || token == "sin" || token == "cos" || token == "tan" ||
                token == "log" || token == "exp") {
                if (stack.isEmpty()) {
                    throw std::out_of_range("Стек пуст, нельзя выполнить операцию.");
                }
                double a = stack.top(); stack.pop();
                double result = commands[token]->execute(a, 0);
                stack.push(result);
            } else {
                stack.push(stod(token));
            }
        }
    }
    return stack.top();
}

// Деструктор
Calculator::~Calculator() {
    for (auto& cmd : commands) {
        delete cmd.second;
    }
}