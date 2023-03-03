//#pragma once
//#include <iostream>
//#include "Casino.h"
//template <typename T>
//class stack
//{
//    T arr[500];
//    int MAXlength;
//    int MINlength;
//    int length;
//
//public:
//    stack();
//    bool isEmpty();
//    bool isFull();
//    void push(T value);
//    T top();
//    void pop();
//    friend std::ostream& operator<<(std::ostream& output, const stack& stk);
//
//};
//
//template<>
//class stack<Casino>
//{
//    Casino arr[500];
//    int MAXlength;
//    int MINlength;
//    int length;
//
//public:
//    stack();
//    bool isEmpty();
//    bool isFull();
//    void push(const Casino& value);
//    Casino top();
//    void pop();
//    friend std::ostream& operator<<(std::ostream& output, const stack& stk);
//
//};
//
//
//stack<Casino>::stack() : MAXlength{500}, length{-1}, MINlength{-1}{}
//
//bool stack<Casino>::isEmpty() {
//    return length == MINlength;
//}
//bool stack<Casino>::isFull()
//{
//    return length + 1 == MAXlength;
//}
//void stack<Casino>::push(const Casino& value)
//{
//    if (!isFull())
//    {
//        arr[++length] = value;
//    }
//    else
//    {
//        std::cout << "Stack is full\n";
//    }
//}
//Casino stack<Casino>::top()
//{
//    if (!isEmpty())
//        return arr[length];
//    else
//        return Casino();
//}
//void stack<Casino>::pop()
//{
//    if (!isEmpty())
//    {
//        length--;
//    }
//}
//
//std::ostream& operator<<(std::ostream& output, const stack<Casino>& stk)
//{
//    for (int i = 0; i < stk.length; i++)
//    {
//        output << stk.arr[i];
//    }
//    return output;
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//template <typename T>
//stack<T>::stack() : MAXlength{500}, length{-1}, MINlength{-1}
//{
//}
//
//template <typename T>
//inline bool stack<T>::isEmpty()
//{
//    return length == MINlength;
//}
//
//template <typename T>
//inline bool stack<T>::isFull()
//{
//    return length + 1 == MAXlength;
//}
//
//template <typename T>
//void stack<T>::push(T value)
//{
//    if (!isFull())
//    {
//        arr[++length] = value;
//    }
//    else
//    {
//        std::cout << "Stack is full\n";
//    }
//}
//
//template <typename T>
//T stack<T>::top()
//{
//    if (!isEmpty())
//        return arr[length];
//    else
//        return T();
//}
//
//template <typename T>
//void stack<T>::pop()
//{
//    if (!isEmpty())
//    {
//        length--;
//    }
//}
