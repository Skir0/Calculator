#include "Calculator.h"

// Конструктор
Calculator::Calculator() {
    commands["+"] = new AddCommand();
    commands["-"] = new SubtractCommand();
    commands["*"] = new MultiplyCommand();
    commands["/"] = new DivideCommand();
    commands["%"] = new ModulusCommand();
    commands["^"] = new PowerCommand();
    commands["sqrt"] = new SqrtCommand();
    commands["sin"] = new SinCommand();
    commands["cos"] = new CosCommand();
    commands["tan"] = new TanCommand();
    commands["log"] = new LogCommand();
    commands["exp"] = new ExpCommand();
    commands["&"] = new BitwiseAndCommand();
    commands["|"] = new BitwiseOrCommand();
    commands["xor"] = new BitwiseXorCommand();
    commands["<<"] = new ShiftLeftCommand();
    commands[">>"] = new ShiftRightCommand();
}

// Метод для вычисления
double Calculator::calculate(const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    Stack<double> stack;

    while (iss >> token) {
        if (commands.find(token) != commands.end()) {
            // Проверка для бинарных операций
            if (token != "sqrt" && token != "sin" && token != "cos" &&
                token != "tan" && token != "log" && token != "exp") {
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
                    // Проверка для унарных операций
                    if (stack.isEmpty()) {
                        throw std::out_of_range("Стек пуст, нельзя выполнить операцию.");
                    }
                    double a = stack.top(); stack.pop();
                    double result = commands[token]->execute(a, 0);
                    stack.push(result);
                }
        } else {
            // Преобразование строки в число и добавление в стек
            stack.push(stod(token));
        }
    }
    // Проверка на наличие результата в стеке перед его возвратом
    if (stack.isEmpty()) {
        throw std::out_of_range("Стек пуст, нет результата.");
    }
    return stack.top();
}

// Деструктор
Calculator::~Calculator() {
    for (auto& cmd : commands) {
        delete cmd.second;
    }
}