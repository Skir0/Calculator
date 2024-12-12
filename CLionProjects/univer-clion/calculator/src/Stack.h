#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

#endif // STACK_H