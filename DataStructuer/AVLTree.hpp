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

typedef enum{
    left,
    right
} LR;

template <class T>
class AVLTree: public BinarySearchTree<T> {
private:
    const bool insert(BSTN<T> * bstn, const T data) override final;  // 插入 ok
//    const bool del(BSTN<T> *bstn) override final;
    const LR is_balance(BSTN<T> * bstn) const;
    void balance(BSTN<T> * bstn);
//    void ll_rotation(BSTN<T> * bstn);
//    void rr_rotation(BSTN<T> * bstn);
//    void lr_rotation(BSTN<T> * bstn);
//    void rl_rotation(BSTN<T> * bstn);
public:
    AVLTree(void);
    AVLTree(const T data);
    ~AVLTree(void);
    const bool Insert(const T data) override final;  // 插入
    const int GetLeaf(void) const override final;  // 返回树叶子节点数量
//    const bool Delete(BSTN<T> *bstn) override final;
};

template <class T>
AVLTree<T>::AVLTree(void){
    this->root=NULL;
    return;
}

template <class T>
AVLTree<T>::AVLTree(const T data){
    this->root=new BSTN<T>(data);
    this->root->data=data;
    return;
}

template <class T>
AVLTree<T>::~AVLTree(void){
    return;
}

template <class T>
const bool AVLTree<T>::insert(BSTN<T> * bstn, const T data){
    if(this->search_in_sub_tree(bstn, data))
        return false;
    if(bstn==NULL){
        bstn=new BSTN<T>(data);
        bstn->data=data;
        return true;
    }
    else{
        BSTN<T> * tmp = NULL;
        while(bstn!=NULL){  // 找到要插入的位置的父节点
            tmp=bstn;
            if(data<bstn->data)
                bstn=bstn->left;
            else if(data>bstn->data)
                bstn=bstn->right;
            else
                return false;
        }
        // 左子树还是右子树
        if(data<tmp->data){
            tmp->left=new BSTN<T>(data);
            tmp=tmp->left;
        }
        else{
            tmp->right=new BSTN<T>(data);
            tmp=tmp->right;
        }
        this->balance(tmp);
        return true;
    }
}

template <class T>
const bool AVLTree<T>::Insert(const T data){
    return this->insert(this->root, data);
}

template <class T>
const LR AVLTree<T>::is_balance(BSTN<T> * bstn) const{
    int tmp=0;
    tmp=this->get_height(bstn->left)-this->get_height(bstn->right);
    return left;
}

template <class T>
void AVLTree<T>::balance(BSTN<T> * bstn){
    return;
}

template <class T>
const int AVLTree<T>::GetLeaf() const{
    return 0;
}


#endif /* AVLTree_hpp */
