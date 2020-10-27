// Copyright 2020 Magellan

#ifndef _ITERATOR1_STACKARRAY_H_
#define _ITERATOR1_STACKARRAY_H_

#include <cassert>

namespace Magellan {

template <class T>
class StackIterator;

template <class T>
class Stack {
    private:
        T *m_array{ nullptr };
        int m_size{ 0 };
        int m_top{ -1 };
        friend class StackIterator<T>;

    public:
        Stack() : m_top{ -1 } {
            m_array = new T[100];
        }

        ~Stack() {
            if (m_array) {
                delete [] m_array;
            }
        }

        bool isEmpty() const {
            return (m_top + 1 == m_size);
        }

        bool isFull() const {
            return (m_top == m_size - 1);
        }

        void push_back(const T &item) {
            m_array[++m_top] = item;
        }

        T pop_back() {
            assert(!isEmpty() && "Stack is empty.");
            T item = m_array[m_top--];
            return item;
        }
};

};  // namespace Magellan

#endif  // _ITERATOR1_STACKARRAY_H_
