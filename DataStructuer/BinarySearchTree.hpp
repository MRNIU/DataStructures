//
//  BinaryTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2018/10/29.
//  Copyright © 2018 Zone.N. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

// Binary search tree node
template <class T>
class BSTN {
public:
    T data;
    BSTN<T> * left;
    BSTN<T> * right;
    BSTN<T> * parent;
    BSTN(void);
    BSTN(T data, BSTN<T> * left=NULL, BSTN<T> * right=NULL);
    ~BSTN(void);
};

template <class T>
BSTN<T>::BSTN(){
    this->data=0;
    this->right=NULL;
    this->left=NULL;
    this->parent=NULL;
    return;
}

template <class T>
BSTN<T>::BSTN(T data, BSTN<T> * left, BSTN<T> * right){
    this->data=data;
    this->left=left;
    this->right=right;
    return;
}

template <class T>
BSTN<T>::~BSTN(){
    return;
}

// Binary search tree
template <class T>
class BinarySearchTree {
private:
    BSTN<T> * root;
    void Sort(BSTN<T> * bstn);
    int IPL(BSTN<T> * bstn) const; // Internal Path Length 内部路径长度
    void BreadthFirstTraversal(BSTN<T> * bstn) const; // 广度优先遍历
    void DepthFirstTraversal_VLR(BSTN<T> * bstn) const; // 深度优先遍历 前序
    void DepthFirstTraversal_LVR(BSTN<T> * bstn) const; // 深度优先遍历 中序
    void DepthFirstTraversal_LRV(BSTN<T> * bstn) const; // 深度优先遍历 后序
    const string DisplayInfo(BSTN<T> * bstn, string msg) const;
    const BSTN<T> * ConverttoBST(T * arr);  // 将数组转换为 BST 算法见 IA 3e 中文版 p84
public:
    BinarySearchTree(void);
    BinarySearchTree(const T data);
    ~BinarySearchTree(void);
    BSTN<T> * Search(const T data) const;
    BSTN<T> * Search(BSTN<T> * bstn, const T data) const;
    bool Empty(void) const;
    void Insert(const T data);
    int GetHeight(BinarySearchTree<T> * bst) const;
    void Clear(BinarySearchTree<T> * bst);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(void){
    root=NULL;
    return;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T data){
    root=new BSTN<T>(data);
    root->data=data;
    return;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree(void){
    return;
}

template <class T>
void BinarySearchTree<T>::Sort(BSTN<T> * bstn){
    if(bstn==NULL) return;
    
}

template <class T>
int BinarySearchTree<T>::IPL(BSTN<T> * bstn) const{
    if(bstn==NULL) return 0;
    return 0;
}



template <class T>
BSTN<T> * BinarySearchTree<T>::Search(const T data) const{
    return Search(root, data);
}

template <class T>
BSTN<T> * BinarySearchTree<T>::Search(BSTN<T> * bstn, const T data) const{
    if(bstn==NULL)  return NULL;
    if(bstn->data!=data){
        if(bstn->left!=NULL){
           return Search(bstn->left, data);
        }
        if(bstn->right!=NULL){
           return Search(bstn->right, data);
        }
        return NULL;    // 没有要找的元素
    }
    return bstn;    // 找到了，返回对应节点指针。
}

template <class T>
bool BinarySearchTree<T>::Empty(void) const{
    return root==NULL;
}

template <class T>
void BinarySearchTree<T>::Insert(const T data){
    
}

template <class T>
int BinarySearchTree<T>::GetHeight(BinarySearchTree<T> * bst) const{
    
}

template <class T>
void BinarySearchTree<T>::Clear(BinarySearchTree<T> * bst){
    
}
#endif /* BinaryTree_h */
