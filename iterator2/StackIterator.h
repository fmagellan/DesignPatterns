// Copyright 2020 Magellan

#ifndef _ITERATOR1_STACKITERATOR_H_
#define _ITERATOR1_STACKITERATOR_H_

#include "iterator2/Stack.h"

#include <cassert>

namespace Magellan {

template <class T>
class StackIterator {
    private:
        const Stack<T> *m_stack{ nullptr };
        int m_index{ -1 };

    public:
        explicit StackIterator(const Stack<T> *pStack)
            : m_stack{ pStack }, m_index{ -1 }
        {
        }

        ~StackIterator() = default;
        T& operator * () {
            assert(!(m_stack->isEmpty()) && "Stack is empty.");

            return (m_stack->m_array[m_index]);
        }

        StackIterator& operator ++ () {
            ++m_index;
            return (*this);
        }

        void start() {
            m_index = 0;
        }

        bool isValid() const {
            return ((m_index >= -1) && (m_index <= m_stack->m_top));
        }

        friend bool operator == (const StackIterator &pLeft, const StackIterator &pRight) {
            return (pLeft.m_index == pRight.m_index);
        }

        friend bool operator != (const StackIterator &pLeft, const StackIterator &pRight) {
            return (pLeft.m_index != pRight.m_index);
        }
};

};  // namespace Magellan

#endif  //_ITERATOR1_STACKITERATOR_H_ 
