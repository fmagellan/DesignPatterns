// Copyright 2020 Magellan

#include "iterator1/StackIterator.h"

#include <cassert>

int& StackIterator::operator * () {
    assert(!(m_stack->isEmpty()) && "Stack is empty.");

    return (m_stack->m_array[m_index]);
}

int& StackIterator::operator ++ () {
    ++m_index;
}

void StackIterator::start() {
    m_index = 0;
}

bool StackIterator::isValid() const {
    return ((m_index >= -1) && (m_index <= m_stack->m_top));
}

bool operator == (const StackIterator &pLeft, const StackIterator &pRight) {
    return (pLeft.m_index == pRight.m_index);
}

bool operator != (const StackIterator &pLeft, const StackIterator &pRight) {
    return (pLeft.m_index != pRight.m_index);
}
