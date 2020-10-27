// Copyright 2020 Magellan

#include "iterator1/StackArray.h"
#include "iterator1/StackIterator.h"

#include <cassert>

Stack::Stack() : m_top{ -1 } {
    m_array = new int[100];
}

Stack::~Stack() {
    if (m_array) {
        delete [] m_array;
    }
}

bool Stack::isEmpty() const {
    return (m_top + 1 == m_size);
}

bool Stack::isFull() const {
    return (m_top == m_size - 1);
}

void Stack::push_back(int item) {
    m_array[++m_top] = item;
}

int Stack::pop_back() {
    assert(!isEmpty() && "Stack is empty.");
    int item = m_array[m_top--];
    return item;
}

StackIterator* Stack::createIterator() {
    return (new StackIterator(this));
}

