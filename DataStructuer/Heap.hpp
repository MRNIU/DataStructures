//
//  Heap.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef HEAP_HPP
#define HEAP_HPP

//template <class T>
//class HPN {
//private:
//    T data;
//    HPN<T> * right;
//    HPN<T> * left;
//public:
//    HPN(void);
//    HPN(T data);
//    ~HPN(void);
//};
//
//template <class T>
//HPN<T>::HPN(){
//    return;
//}
//
//template <class T>
//HPN<T>::HPN(T data){
//    return;
//}
//
//template <class T>
//HPN<T>::~HPN(){
//    delete right;
//    delete left;
//    return;
//}

// Max Heap
template <class T>
class Heap {
private:
//    HPN<T> * top;
    T * ves;
    size_t curr_size;
    size_t max_size = 100;
public:
    Heap(void);
    Heap(T * arr, size_t size);
    ~Heap(void);
    virtual const bool arry2heap(T * arr, size_t size);   // 数组转换为堆
    virtual const bool push(T data);    // 插入元素
    virtual const T pop(void);  // 弹出堆顶元素
    virtual const T get_top(void);  // 获取堆顶元素
    virtual const Heap<T> merge(Heap<T> * des, Heap<T> * res);   // 合并两个堆，返回新的堆
};

template <class T>
Heap<T>::Heap(){
    ves = (int *)malloc(max_size * sizeof(T));
    return;
}

template <class T>
Heap<T>::Heap(T * arr, size_t size){
    ves = (int *)malloc(2 * size * sizeof(T));
    for(int i = 0; i < size; i++){
        ves[i] = arr[i];
    }
    return;
}

template <class T>
Heap<T>::~Heap(){
    delete ves;
    return;
}

template <class T>
const bool Heap<T>::arry2heap(T * arr, size_t size){
    return true;
}

template <class T>
const bool Heap<T>::push(T data){
    return true;
}

template <class T>
const T Heap<T>::pop(){
    return 0;
}

template <class T>
const T Heap<T>::get_top(){
    return 0;
}

template <class T>
const Heap<T> Heap<T>::merge(Heap<T> * des, Heap<T> * res){
    return Heap<T>();
}


#endif /* HEAP_HPP */
