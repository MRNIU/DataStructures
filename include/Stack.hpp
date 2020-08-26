//
//  Stack.hpp
//  DS
//
//  Created by Zone.Niuzh on 2018/9/25.
//  Copyright © 2018 MRNIU. All rights reserved.
//
// 栈的链表实现

#ifndef STACK_HPP
#define STACK_HPP
#include "LinkedList.hpp"

template <class T>
class Stack {
private:
    LinkedList<T> LL;

public:
    void test(void);    // 测试函数
    Stack(void);
    Stack(const T data);
    ~Stack();
    T Top(void) const;    // 返回栈顶数据
    T Bottom(void) const; // 返回栈底数据
    T Pop(void);    // 出栈
    void Push(const T data);  // 压栈
    int Size(void) const; // 返回栈的大小
    bool Empty(void) const;   // 判断栈是否为空
    const size_t ToArray(T arr[]) const;
    const size_t ToVector(std::vector<T> &vect) const;
    void Display(void) const;
};

template <class T>
Stack<T>::Stack(const T data) {
    LL.AddtoHead(data);
    return;
}

template <class T>
Stack<T>::Stack() {
    return;
}

template <class T>
Stack<T>::~Stack() {
    LL.~LinkedList<T>();
    return;
}

template <class T>
T Stack<T>::Top() const {
    return LL.GetHead();
}

template <class T>
T Stack<T>::Bottom() const {
    return LL.GetTail();
}

template <class T>
T Stack<T>::Pop() {
    return LL.RemoveFromHead();
}

template <class T>
void Stack<T>::Push(const T data_input) {
    LL.AddtoHead(data_input);
    return;
}

template <class T>
bool Stack<T>::Empty() const {
    return LL.Empty();
}

template <class T>
int Stack<T>::Size() const {
    return LL.Size();
}

template <class T>
const size_t Stack<T>::ToArray(T arr[]) const {
    return LL.ToArray(arr);
}

template <class T>
const size_t Stack<T>::ToVector(std::vector<T> &vect) const {
    return LL.ToVector(vect);
}

template <class T>
void Stack<T>::Display(void) const {
    LL.Display();
    return;
}

#endif /* STACK_HPP */
