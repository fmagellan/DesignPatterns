// Copyright 2020 Magellan

#ifndef _ITERATOR1_STACKITERATOR_H_
#define _ITERATOR1_STACKITERATOR_H_

#include "iterator1/StackArray.h"

class StackIterator {
    private:
        const Stack *m_stack{ nullptr };
        int m_index{ -1 };

    public:
        explicit StackIterator(const Stack *pStack)
            : m_stack{ pStack }, m_index{ -1 }
        {
        }

        ~StackIterator() = default;
        int& operator * ();
        int& operator ++ ();
        void start();
        bool isValid() const;

        friend bool operator == (const StackIterator &pLeft, const StackIterator &pRight);
        friend bool operator != (const StackIterator &pLeft, const StackIterator &pRight);
};

#endif  //_ITERATOR1_STACKITERATOR_H_ 
