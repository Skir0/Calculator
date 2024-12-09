#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual double execute(double a, double b) = 0;
    virtual ~Command() = default; // Виртуальный деструктор
};

// Арифметические команды
class AddCommand : public Command {
public:
    double execute(double a, double b) override {
        return a + b;
    }
};

class SubtractCommand : public Command {
public:
    double execute(double a, double b) override {
        return a - b;
    }
};

class MultiplyCommand : public Command {
public:
    double execute(double a, double b) override {
        return a * b;
    }
};

class DivideCommand : public Command {
public:
    double execute(double a, double b) override {
        if (b == 0) throw std::invalid_argument("Деление на ноль");
        return a / b;
    }
};

class ModulusCommand : public Command {
public:
    double execute(double a, double b) override {
        return static_cast<int>(a) % static_cast<int>(b);
    }
};

class PowerCommand : public Command {
public:
    double execute(double a, double b) override {
        return std::pow(a, b);
    }
};



#endif // COMMAND_H