//
//  AVLTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2019/2/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

#define BALANCE_FACTOR 2

template <class T>
class AVLN {
public:
    T data;
    int balance_factor;
    AVLN<T> * left;
    AVLN<T> * right;
    AVLN(void);
    AVLN(T data, int factor = 0, AVLN<T> * left = NULL, AVLN<T> * right = NULL);
    ~AVLN(void);
};

template <class T>
AVLN<T>::AVLN(){
    this->data = NULL;
    this->right = NULL;
    this->left = NULL;
    return;
}

template <class T>
AVLN<T>::AVLN(T data, int factor, AVLN<T> * left, AVLN<T> * right){
    this->data = data;
    this->balance_factor = factor;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
AVLN<T>::~AVLN(){
    delete this->left;
    delete this->right;
    return;
}

template <template<class> class N, class T>
class AVLTree: public BinarySearchTree<N, T> {
private:
    const bool insert(N<T> * avln, const T data) override final;
    const bool clean(N<T> * avln) override final;
    const bool update_balance_factor(BSTN<T> * avln);
    
public:
    AVLTree(void);
    AVLTree(const T data);
    AVLTree(const T * arr, const size_t begin, const size_t end);
    ~AVLTree(void);
    
    const bool Insert(const T data) override final;  // 插入
    const bool Delete(const T data) override final; // 删除
};

template <template<class> class N, class T>
AVLTree<N, T>::AVLTree(void): BinarySearchTree<N, T>::BinarySearchTree(){
    return;
}

template <template<class> class N, class T>
AVLTree<N, T>::AVLTree(const T data): BinarySearchTree<N, T>::BinarySearchTree(data){
    return;
}

template <template<class> class N, class T>
AVLTree<N, T>::AVLTree(const T * arr, const size_t begin, const size_t end): BinarySearchTree<N, T>::BinarySearchTree(arr, begin, end){
    return;
}

template <template<class> class N, class T>
AVLTree<N, T>::~AVLTree(void){
    this->clean(this->root);
    return;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::insert(N<T> * avln, const T data){
    return true;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::Insert(const T data){
    return this->insert(this->root, data);
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::clean(N<T> * avln){
    return true;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::Delete(const T data){
    return true;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::update_balance_factor(BSTN<T> * avln){
    
    return true;
}

#endif /* AVLTree_hpp */
