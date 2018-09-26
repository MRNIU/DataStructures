//
//  Stack.hpp
//  DS
//
//  Created by Zone.Niuzh on 2018/9/25.
//  Copyright © 2018 MRNIU. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "LinkedList.hpp"

template <class T>
class Stack {
private:
    LinkedList<T> LL;
public:
    void test(void);    // 测试函数
    Stack(void);
    Stack(T data);
    ~Stack();
    T Top(void);    // 返回栈顶数据
    T Bottom(void); // 返回栈底数据
    T Pop(void);    // 出栈
    void Push(T data);  // 压栈
    int Size(void); // 返回栈的大小
    bool Empty(void);   // 判断栈是否为空
};

template <class T>
Stack<T>::Stack(T data){
    LL.AddtoHead(data);
}

template <class T>
Stack<T>::Stack(){
    LL;
}

template <class T>
T Stack<T>::Top(){
    return LL.GetHead();
}

template <class T>
T Stack<T>::Bottom(){
    return LL.GetTail();
}

template <class T>
T Stack<T>::Pop(){
    return LL.RemoveFromHead();
}

template <class T>
void Stack<T>::Push(T data_input){
    LL.AddtoHead(data_input);
    return;
}

template <class T>
bool Stack<T>::Empty(){
    return LL.Empty();
}

template <class T>
int Stack<T>::Size(){
    return LL.size();
}

template <class T>
Stack<T>::~Stack(){
    LL.~LinkedList<T>();
}

template <class T>
void Stack<T>::test(void){
    LL.test();
}

#endif /* Stack_h */
