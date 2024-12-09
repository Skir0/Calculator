#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;
    std::string expression;
    int mode;

    while (true) {
        std::cout << "\nВыберите режим:\n";
        std::cout << "1. Обычные операции\n";
        std::cout << "2. Инженерные операции\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите номер режима: ";
        std::cin >> mode;
        std::cin.ignore(); // Игнорируем символ новой строки после ввода номера режима

        if (mode == 0) {
            break;
        }

        if (mode == 1) {
            while (true) {
                std::cout << "\n+  Сложение\n";
                std::cout << "-  Вычитание\n";
                std::cout << "*  Умножение\n";
                std::cout << "/  Деление\n";
                std::cout << "%  Остаток от деления\n";
                std::cout << "^  Возведение в степень\n";
                std::cout << "exit  Вернуться в меню режимов\n";

                std::cout << "Введите выражение в обратной польской записи: ";
                std::getline(std::cin, expression);

                if (expression == "exit") {
                    break;
                }

                try {
                    double result = calc.calculate(expression);
                    std::cout << "Результат: " << result << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
            }
        }
    }

    return 0;
}