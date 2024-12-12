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

// Инженерные команды
class SqrtCommand : public Command {
public:
    double execute(double a, double) override {
        return std::sqrt(a);
    }
};

class SinCommand : public Command {
public:
    double execute(double a, double) override {
        return std::sin(a);
    }
};

class CosCommand : public Command {
public:
    double execute(double a, double) override {
        return std::cos(a);
    }
};

class TanCommand : public Command {
public:
    double execute(double a, double) override {
        return std::tan(a);
    }
};

class LogCommand : public Command {
public:
    double execute(double a, double) override {
        if (a <= 0) throw std::invalid_argument("Логарифм определён только для положительных чисел");
        return std::log(a);
    }
};

class ExpCommand : public Command {
public:
    double execute(double a, double) override {
        return std::exp(a);
    }
};

// Битовые команды
class BitwiseAndCommand : public Command {
public:
    double execute(double a, double b) override {
        return static_cast<int>(a) & static_cast<int>(b);
    }
};

class BitwiseOrCommand : public Command {
public:
    double execute(double a, double b) override {
        return static_cast<int>(a) | static_cast<int>(b);
    }
};

class BitwiseXorCommand : public Command {
public:
    double execute(double a, double b) override {
        return static_cast<int>(a) ^ static_cast<int>(b);
    }
};

class ShiftLeftCommand : public Command {
public:
    double execute(double a, double b) override {
        return static_cast<int>(a) << static_cast<int>(b);
    }
};

class ShiftRightCommand : public Command {
public:
    double execute(double a, double b) override {
        return static_cast<int>(a) >> static_cast<int>(b);
    }
};

#endif // COMMAND_H