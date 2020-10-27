// Copyright 2020 Magellan

#ifndef _ITERATOR1_STACKARRAY_H_
#define _ITERATOR1_STACKARRAY_H_

class StackIterator;

class Stack {
    private:
        int *m_array{ nullptr };
        int m_size{ 0 };
        int m_top{ -1 };
        friend class StackIterator;

    public:
        Stack();
        ~Stack();

        bool isEmpty() const;
        bool isFull() const;
        void push_back(int item);
        int pop_back();

        StackIterator* createIterator();
};

#endif  // _ITERATOR1_STACKARRAY_H_
