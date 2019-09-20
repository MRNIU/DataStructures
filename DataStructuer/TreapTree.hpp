//
//  TreapTree.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef TREAPTREE_HPP
#define TREAPTREE_HPP

#include "BinarySearchTree.hpp"

// 树堆的二叉树旋转实现
template <class T>
class TREN {
public:
    T data;
    int priority;
    TREN<T> * left;
    TREN<T> * right;
    TREN<T> * parent;
    TREN(void);
    TREN(T data, int priority = 0, TREN<T> * parent = nullptr, TREN<T> * left = nullptr, TREN<T> * right = nullptr);
    ~TREN(void);
};


template <class T>
TREN<T>::TREN(){
    this->data = nullptr;
    this->priority = 0;
    this->right = nullptr;
    this->left = nullptr;
    return;
}

template <class T>
TREN<T>::TREN(T data, int priority, TREN<T> * parent, TREN<T> * left, TREN<T> * right){
    this->data = data;
    this->priority = priority;
    this->parent = parent;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
TREN<T>::~TREN(){
    delete left;
    delete right;
    delete parent;
    return;
}

template <class T>
class TreapTree : public BinarySearchTree<T, TREN>{
private:
    const bool insert(TREN<T> * tren, const T data, const int priority);
    const bool del(TREN<T> * tren, const T data);
//    const bool search(const TREN<T> * tren, const T data) const;
    void display_tree(TREN<T> * tren) const;
    void rotate(TREN<T> * ch, TREN<T> * par, TREN<T> * grand);
    void rotate_left(TREN<T> * ch, TREN<T> * par, TREN<T> * grand);
    void rotate_right(TREN<T> * ch, TREN<T> * par, TREN<T> * grand);
    const int generate_random_priority(void) const;
    
public:
    TreapTree(void);
    TreapTree(const T data, const int priority = 0);
    ~TreapTree(void);
    
    const bool Insert(const T data);
    const bool Delete(const T data);

    
};

template <class T>
TreapTree<T>::TreapTree(){
    this->root = nullptr;
    return;
}

template <class T>
TreapTree<T>::TreapTree(const T data, const int priority){
    this->root = new TREN<T>(data, priority);
    return;
}

template <class T>
TreapTree<T>::~TreapTree(){
//    delete this->root;
    return;
}

template <class T>
const int TreapTree<T>::generate_random_priority() const{
    return  (rand() % (1000-0+1))+ 0;
}

template <class T>
const bool TreapTree<T>::del(TREN<T> * tren, const T data){
    if(tren == nullptr){
        return false;
    }
    
    // 要删除的节点是叶节点
    if(tren->left == nullptr && tren->right == nullptr){
        if(tren->parent->left == tren){
            tren->parent->left = nullptr;
        }
        else{
            tren->parent->right = nullptr;
        }
        delete tren;
    }
    // 有左子树，没有右子树
    else if(tren->left != nullptr && tren->right == nullptr){
        
    }
    // 有右子树，没有左子树
    else if(tren->right != nullptr && tren->left == nullptr){
        
    }
    // 有两个子树
    else{
        
    }
    
    
    while (tren != nullptr) {
        if(tren->left->priority < tren->right->priority){
            this->rotate_right(tren->right, tren, tren->parent);
            tren = tren->right;
        }
        else{
            this->rotate_left(tren->left, tren, tren->parent);
            tren = tren->left;
        }
    }
    
    return true;
}

template <class T>
const bool TreapTree<T>::insert(TREN<T> * tren, const T data, const int priority){
    if(this->search(tren, data))
        return false;
    
    // 树为空的情况
    if(tren == nullptr) {
        tren = new TREN<T>(data, priority);
        if(this->root == nullptr){
            this->root = tren;
        }
        return true;
    }

    TREN<T> * ch = tren,
    * par = nullptr;
    
    while(ch != nullptr){
        par = ch;
        if(data < ch->data)
            ch = ch->left;
        else if(data > ch->data)
            ch = ch->right;
        else
            return false;
    }
    
    if(data < par->data){
        par->left = new TREN<T>(data, priority, par);
        ch = par->left;
        this->rotate(ch, ch->parent, ch->parent->parent);
        
    }
    else{
        par->right = new TREN<T>(data, priority, par);
        ch = par->right;
        this->rotate(ch, ch->parent, ch->parent->parent);
    }
    this->display_tree(this->root);
    return true;

}

template <class T>
void TreapTree<T>::rotate(TREN<T> * ch, TREN<T> * par, TREN<T> * grand){
    while(ch != this->root && par->priority < ch->priority){
        if(par->left == ch){
            this->rotate_right(ch, par, grand);
        }
        else{
            this->rotate_left(ch, par, grand);
        }
        
        if(ch == this->root){
            par =  nullptr;
            grand = nullptr;
        }
        else{
            par = ch->parent;
            grand = par->parent;
        }
    }
    return;
}

template <class T>
void TreapTree<T>::rotate_left(TREN<T> * ch, TREN<T> * par, TREN<T> * grand){
    if(grand == nullptr){
        this->root = par->right;
        par->right->parent = nullptr;
    }
    else {
        if(grand->left == par){
            grand->left = ch;
        }
        else if(grand->right == par){
            grand->right = ch;
        }
        ch->parent = grand;
    }
    
    par->right = ch->left;
    if(ch->left != nullptr){
        ch->left->parent = par;
    }
    ch->left = par;
    par->parent = ch;
    return;
}

template <class T>
void TreapTree<T>::rotate_right(TREN<T> * ch, TREN<T> * par, TREN<T> * grand){
    if(grand == nullptr){
        this->display_tree(this->root);
        this->root = par->left;
        par->left->parent = nullptr;
    }
    else {
        if(grand->left == par){
            grand->left = ch;
        }
        else if(grand->right == par){
            grand->right = ch;
        }
        ch->parent = grand;
    }
    
    par->left = ch->right;
    if(ch->right != nullptr){
        ch->right->parent = par;
    }
    ch->right = par;
    par->parent = ch;
    return;
}

template <class T>
void TreapTree<T>::display_tree(TREN<T> * tren) const {
    std::cout<<"display_tree"<<std::endl;
    
    if(this->root != nullptr)
        std::cout<<"root: "<<this->root->data<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"lvr"<<std::endl;
    this->dfs_lvr(tren, [&](TREN<T>* tren){
        std::cout<<tren->data<<" priority: "<<tren->priority<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"lrv"<<std::endl;
    this->dfs_lrv(tren, [&](TREN<T> * tren){
        std::cout<<tren->data<<" priority: "<<tren->priority<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"bfs"<<std::endl;
    this->bfs(tren, [&](TREN<T> * tren){
        std::cout<<tren->data<<" priority: "<<tren->priority<<std::endl;
    });
    
    std::cout<<std::endl;
    return;
}

template <class T>
const bool TreapTree<T>::Insert(const T data){
    return this->insert(this->root, data, this->generate_random_priority());
}

template <class T>
const bool TreapTree<T>::Delete(const T data){
    return this->del(this->root, data);
}


// 树堆的二叉树无旋实现



#endif /* TREAPTREE_HPP */
