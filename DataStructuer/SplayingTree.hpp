//
//  SplayingTree.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef SPLAYINGTREE_HPP
#define SPLAYINGTREE_HPP

#include "BinarySearchTree.hpp"


template <class T>
class SPYN {
public:
    T data;
    SPYN<T> * parent;
    SPYN<T> * left;
    SPYN<T> * right;
    SPYN(void);
    SPYN(T data, SPYN<T> * left = NULL, SPYN<T> * right = NULL);
    ~SPYN(void);
};

template <class T>
SPYN<T>::SPYN() {
    this->data = 0;
    this->parent = NULL;
    this->right = NULL;
    this->left = NULL;
    return;
}

template <class T>
SPYN<T>::SPYN(T data, SPYN<T> * left, SPYN<T> * right) {
    this->data = data;
    this->parent = NULL;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
SPYN<T>::~SPYN(){
    return;
}

template <class T>
class SPYTree: public BinarySearchTree<T, SPYN> {
protected:
    const bool insert(SPYN<T> * avln, const T data) override final;
    void display_tree(SPYN<T> * bstn) const override final; // 打印树结构 ok
    
public:
    SPYTree(void);
    SPYTree(const T data);
    SPYTree(const T * arr, const size_t begin, const size_t end);
    ~SPYTree(void);
    
    
    const bool Insert(const T data) override final;  // 插入
    const bool Delete(const T data) override final; // 删除
    const bool Search(const T data) const override final;
};

template <class T>
SPYTree<T>::SPYTree(void): BinarySearchTree<T, SPYN>::BinarySearchTree(){
    return;
}

template <class T>
SPYTree<T>::SPYTree(const T data): BinarySearchTree<T, SPYN>::BinarySearchTree(data){
    return;
}

template <class T>
SPYTree<T>::SPYTree(const T * arr, const size_t begin, const size_t end): BinarySearchTree<T, SPYN>::BinarySearchTree(arr, begin, end){
    return;
}

template <class T>
SPYTree<T>::~SPYTree(void){
    return;
}

template <class T>
const bool SPYTree<T>::insert(SPYN<T> * avln, const T data) {
    return true;
}

template <class T>
void SPYTree<T>::display_tree(SPYN<T> * bstn) const {
    return;
}

template <class T>
const bool SPYTree<T>::Insert(const T data) {
    return true;
}

template <class T>
const bool SPYTree<T>::Delete(const T data) {
    return true;
}

template <class T>
const bool SPYTree<T>::Search(const T data) const {
    return true;
}

#endif /* SPLAYINGTREE_HPP */
