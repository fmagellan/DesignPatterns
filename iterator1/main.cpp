// Copyright 2020 Magellan

#include "iterator1/StackIterator.h"

#include <iostream>

int main() {
    Stack s;
    s.push_back(10);
    s.push_back(9);
    s.push_back(8);
    s.push_back(7);
    s.push_back(6);
    s.push_back(5);
    s.push_back(4);

    StackIterator *pItr = s.createIterator();
    pItr->start();
    std::cout << "Elements: ";
    while (pItr->isValid()) {
        std::cout << *(*pItr) << ' ';
        ++(*pItr);
    }

    std::cout << '\n';

    return (0);
}
