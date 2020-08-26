//
//  Queue.hpp
//  DataStructuer
//
//  Created by Zone.Niuzh on 2018/9/27.
//  Copyright © 2018 MRNIU. All rights reserved.
//
// 队列的链表实现

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "LinkedList.hpp"
#include "iostream"

template <class T>
class Queue {
private:
    LinkedList<T> LL;

public:
    Queue();
    Queue(const T data);
    ~Queue();
    void EnQueue(const T data);
    T DeQueue(void);
    bool Empty(void) const;
    T GetFirst(void) const;
    const size_t Size(void) const;
    const size_t ToArray(T arr[]) const;
    const size_t ToVector(std::vector<T> &vect) const;
    void Display(void) const;
};

template <class T>
Queue<T>::Queue() {
    return;
}

template <class T>
Queue<T>::Queue(const T data) {
    LL.AddtoTail(data);
    return;
}

template <class T>
Queue<T>::~Queue() {
    LL.~LinkedList<T>();
    return;
}

template <class T>
void Queue<T>::EnQueue(const T data) {
    LL.AddtoTail(data);
    return;
}

template <class T>
T Queue<T>::DeQueue() {
    return LL.RemoveFromHead();
}

template <class T>
bool Queue<T>::Empty() const {
    return LL.Empty();
}

template <class T>
T Queue<T>::GetFirst() const {
    return LL.GetHead();
}

template <class T>
const size_t Queue<T>::Size(void) const {
    return LL.Size();
}

template <class T>
const size_t Queue<T>::ToArray(T arr[]) const {
    return LL.ToArray(arr);
}

template <class T>
const size_t Queue<T>::ToVector(std::vector<T> &vect) const {
    return LL.ToVector(vect);
}

template <class T>
void Queue<T>::Display(void) const {
    LL.Display();
    return;
}

#endif /* QUEUE_HPP */
