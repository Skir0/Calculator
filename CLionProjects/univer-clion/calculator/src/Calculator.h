#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <map>
#include <string>
#include <sstream>
#include "Stack.h"
#include "Command.h"

class Calculator {
private:
    std::map<std::string, Command*> commands;

public:
    Calculator();
    double calculate(const std::string& input);
    ~Calculator();
};

#endif // CALCULATOR_H