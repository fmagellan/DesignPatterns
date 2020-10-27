// Copyright 2020 Magellan

#include "iterator2/Stack.h"
#include "iterator2/StackIterator.h"

#include <iostream>

template <class T>
Magellan::StackIterator<T>* createIterator(const Magellan::Stack<T> *stack) {
    return (new Magellan::StackIterator<T>(stack));
}

int main() {
    Magellan::Stack<double> s;
    s.push_back(10);
    s.push_back(9);
    s.push_back(8);
    s.push_back(7);
    s.push_back(6);
    s.push_back(5);
    s.push_back(4);

    Magellan::StackIterator<double> *pItr = createIterator(&s);
    pItr->start();
    std::cout << "Elements: ";
    while (pItr->isValid()) {
        std::cout << *(*pItr) << ' ';
        ++(*pItr);
    }

    std::cout << '\n';

    return (0);
}
