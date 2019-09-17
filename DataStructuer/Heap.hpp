//
//  Heap.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef HEAP_HPP
#define HEAP_HPP

#include "AVLTree.hpp"

template <class T>
class HPN {
public:
    T data;
    HPN<T> * left;
    HPN<T> * right;
    HPN(void);
    HPN(T data, HPN<T> * left = nullptr, HPN<T> * right = nullptr);
    ~HPN(void);
};

template <class T>
HPN<T>::HPN(){
    this->data = nullptr;
    this->right = nullptr;
    this->left = nullptr;
    return;
}

template <class T>
HPN<T>::HPN(T data, HPN<T> * left, HPN<T> * right){
    this->data = data;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
HPN<T>::~HPN(){
    delete left;
    delete right;
    return;
}




#endif /* HEAP_HPP */
