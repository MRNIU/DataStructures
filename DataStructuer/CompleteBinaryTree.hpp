//
//  CompleteBinaryTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2019/1/31.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef CompleteBinaryTree_hpp
#define CompleteBinaryTree_hpp

#include "BinarySearchTree.hpp"

template <class T>
class CompleteBinaryTree: public BinarySearchTree<T> {
protected:
    bool insert(BSTN<T> * bstn, const T data) const override final;  // 插入 ok
public:
    CompleteBinaryTree(void);
    CompleteBinaryTree(const T data);
    ~CompleteBinaryTree(void);
    bool Search(const T data) const override final;   // 搜索 data
    bool Insert(const T data) override final;  // 插入
    int GetHeight(void) const override final;  // 返回树高
    int GetLeaf(void) const override final;  // 返回树叶子节点数量
};

template <class T>
CompleteBinaryTree<T>::CompleteBinaryTree(void){
    this->root=NULL;
    return;
}

template <class T>
CompleteBinaryTree<T>::CompleteBinaryTree(const T data){
    this->root=new BSTN<T>(data);
    this->root->data=data;
    return;
}

template <class T>
CompleteBinaryTree<T>::~CompleteBinaryTree(void){
    return;
}

template <class T>
bool CompleteBinaryTree<T>::Insert(const T data){
    return this->insert(this->root, data);
}

template <class T>
int CompleteBinaryTree<T>::GetHeight() const{
    return BinarySearchTree<T>::get_height(this->root);
}

template <class T>
int CompleteBinaryTree<T>::GetLeaf() const{
    return BinarySearchTree<T>::get_leaf(this->root);
}

template <class T>
bool CompleteBinaryTree<T>::Search(const T data) const{
    return BinarySearchTree<T>::search_in_sub_tree(this->root, data);
}

template <class T>
bool CompleteBinaryTree<T>::insert(BSTN<T> * bstn, const T data) const{
    if(bstn==NULL){
        bstn=new BSTN<T>(data);
        bstn->data=data;
        return true;
    }
    else{
        BSTN<T> * tmp = NULL;
        while(bstn!=NULL){
            tmp=bstn;
            if(data<bstn->data)
                bstn=bstn->left;
            else if(data>bstn->data)
                bstn=bstn->right;
            else
                return false;
        }
        if(data<tmp->data)
            tmp->left=new BSTN<T>(data);
        else
            tmp->right=new BSTN<T>(data);
        return true;
    }
}

#endif /* CompleteBinaryTree_hpp */
