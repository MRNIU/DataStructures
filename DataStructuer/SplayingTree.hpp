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
#include "AVLTree.hpp"


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
    const bool insert(SPYN<T> * spyn, const T data) override final;
    const bool search(SPYN<T> * spyn, const T data) const override final;
    
    const bool splaying(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand);
    
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
const bool SPYTree<T>::splaying(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand) {
    while(ch != this->root){
        if(par == this->root){
            // 单一 splaying，ch 围绕 par 右旋
            this->rotate_right(ch, par, grand);
        }
        // ch 与其祖先同构
        else if((grand->left == par && par->left == ch) || (grand->right == par && par->right == ch)){
            // 同构 splaying，par 围绕 grand 右旋，ch 围绕 par 右旋
            this->rotate_right(par, grand, NULL);
            this->rotate_right(ch, par, NULL);
        }
        // ch 与其祖先异构
        else {
            // 异构 splaying，ch 围绕 par 左旋，ch 围绕 grand 右旋
            this->rotate_left(ch, par, grand);
            this->rotate_right(ch, grand, NULL);
        }
    }
    return true;
}

template <class T>
const bool SPYTree<T>::insert(SPYN<T> * spyn, const T data) {
    return true;
}

template <class T>
const bool SPYTree<T>::search(SPYN<T> * spyn, const T data) const {
    return true;
}

template <class T>
void SPYTree<T>::display_tree(SPYN<T> * spyn) const {
    std::cout<<"display_tree"<<std::endl;
    
    if(this->root != NULL)
        std::cout<<"root: "<<this->root->data<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"lvr"<<std::endl;
    this->dfs_lvr(spyn, [&](SPYN<T>* spyn){
        std::cout<<spyn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"lrv"<<std::endl;
    this->dfs_lrv(spyn, [&](SPYN<T> * spyn){
        std::cout<<spyn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"bfs"<<std::endl;
    this->bfs(spyn, [&](SPYN<T> * spyn){
        std::cout<<spyn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    return;
}

template <class T>
const bool SPYTree<T>::Insert(const T data) {
    this->insert(this->root, data);
    return true;
}

template <class T>
const bool SPYTree<T>::Delete(const T data) {
    
    return true;
}

template <class T>
const bool SPYTree<T>::Search(const T data) const {
    this->search(this->root, data);
    return true;
}

#endif /* SPLAYINGTREE_HPP */
