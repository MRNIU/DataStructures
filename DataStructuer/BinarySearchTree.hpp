//
//  BinarySearchTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2018/10/29.
//  Copyright © 2018 Zone.N. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Queue.hpp"
#include "math.h"

template <class T>
class BSTN {
public:
    T data;
    BSTN<T> * left;
    BSTN<T> * right;
    BSTN(void);
    BSTN(T data, BSTN<T> * left=NULL, BSTN<T> * right=NULL);
    ~BSTN(void);
};

template <class T>
BSTN<T>::BSTN(){
    this->data = NULL;
    this->right = NULL;
    this->left = NULL;
    return;
}

template <class T>
BSTN<T>::BSTN(T data, BSTN<T> * left, BSTN<T> * right){
    this->data = data;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
BSTN<T>::~BSTN(){
    return;
}

template <class T>
class BinarySearchTree {
protected:
    BSTN<T> * root; // 保存树根节点
    
    virtual void clean(BSTN<T> *bstn);  // 删除以指定节点为根的树 ok
    
    virtual const bool del_merge(BSTN<T> * &bstn);    // 合并删除 ok
    virtual const bool find_and_del_by_merge(const T data); // ok
    virtual const bool del_copy(BSTN<T> * &bstn);    // 复制删除 ok
    virtual const bool find_and_del_by_copy(const T data); // ok
    
    virtual const bool insert(BSTN<T> * bstn, const T data);  // 插入 ok
    const bool search(BSTN<T> * bstn, const T data) const;   // 在指定子树中搜索 data ok
    
    void bfs(BSTN<T> *bstn, std::function<void (BSTN<T>*)> fun) const;  // 广度优先遍历 ok
    void dfs_vlr(BSTN<T> * bstn, std::function<void (BSTN<T>*)> fun) const; // VLR 遍历 ok
    void dfs_lvr(BSTN<T> * bstn, std::function<void (BSTN<T>*)> fun) const; // LVR 遍历 ok
    void dfs_lrv(BSTN<T> * bstn, std::function<void (BSTN<T>*)> fun) const; // LRV 遍历 ok
    
    void balance_dsw(BSTN<T> * bstn);   // DSW 平衡算法 ok
    void dsw_create_backbone(BSTN<T> * ch, BSTN<T> * bstn, BSTN<T> * par); // dsw 算法，创建主链 ok
    void dsw_recreate_tree(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand);   // dsw 算法，重新生成树 ok
    
    void bsw_rotate_right(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand); // 右旋 ok
    void bsw_rotate_left(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand); // 左旋 ok
    
    virtual void display_tree(BSTN<T> * bstn) const; // 打印树结构 ok
    const int ipl(BSTN<T> * bstn) const; // Internal Path Length 内部路径长度
    virtual const int get_height(BSTN<T> *bstn) const; // 返回指定树的树高 ok
    virtual const int get_leaf(BSTN<T> *bstn) const;  // 返回以指定节点为根的树的叶子结点数量 ok
    virtual const int get_nodes(BSTN<T> * bstn) const;    // 返回以指定节点为根的树的结点数量 ok
    
    void debug(void);
    
public:
    BinarySearchTree(void);
    BinarySearchTree(const T data);
    BinarySearchTree(const T * arr, const size_t begin, const size_t end);
    virtual ~BinarySearchTree(void);
    
    const bool Search(const T data) const;   // 搜索 data ok
    virtual const bool Insert(const T data);  // 插入 ok
    virtual const bool Delete(const T data);   // 删除
    
    
    virtual const bool Empty(void) const; // 返回是否为空 ok
    virtual const int GetHeight(void) const;  // 返回树高
    virtual const int GetLeaf(void) const;  // 返回树叶子节点数量
    virtual const int GetNodes(void) const;   // 返回树节点数量
    virtual const void DisplayTree(void) const;   // 打印树结构
    
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(void){
    this->root = NULL;
    return;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T data){
    this->root=new BSTN<T>(data);
    this->root->data=data;
    return;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T * arr, const size_t begin, const size_t end) {
    size_t mid = (begin + end) / 2;
    
    if(begin <= end){
        this->insert(this->root, arr[mid]);
        this->array_to_bst(arr, begin, mid - 1);
        this->array_to_bst(arr, mid + 1, end);
    }
    
    return;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree(void){
    this->clean(this->root);
    return;
}

template <class T>
void BinarySearchTree<T>::clean(BSTN<T> * bstn){
    if(bstn != NULL){
        clean(bstn->left);
        clean(bstn->right);
        delete bstn;
    }
    return;
}

template <class T>
const int BinarySearchTree<T>::ipl(BSTN<T> * bstn) const{
    int ipl = 0;
    // TODO
    return ipl;
}

template <class T>
const bool BinarySearchTree<T>::Search(const T data) const{
    return search(this->root, data);
}

template <class T>
const bool BinarySearchTree<T>::search(BSTN<T> * bstn, const T data) const{
    if(bstn == NULL)  return false;
    if(data < bstn->data)
        return search(bstn->left, data);
    else if(data > bstn->data)
        return search(bstn->right, data);
    else
        return true;    // 找到了，返回对应节点指针。
}

template <class T>
const bool BinarySearchTree<T>::Empty(void) const{
    return this->root == NULL;
}

template <class T>
const bool BinarySearchTree<T>::del_merge(BSTN<T> * &bstn){
    BSTN<T> * tmp = bstn;
    if(bstn != NULL){
        if(bstn->right == NULL){
            bstn = bstn->left;
        }
        else if(bstn->left == NULL){
            bstn = bstn->right;
        }
        else{
            tmp = bstn->left;
            while(tmp->right != NULL){
                tmp = tmp->right;
            }
            tmp->right = bstn->right;
            tmp = bstn;
            bstn = bstn->left;
        }
        delete tmp;
    }
    return true;
}

template <class T>
const bool BinarySearchTree<T>::find_and_del_by_merge(const T data){
    BSTN<T> * node = this->root,
            * prev = NULL;
    while(node != 0){
        if(node->data == data){
            break;
        }
        prev = node;
        if(node->data < data) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    if(node != 0 && node->data == data){
        if(node == this->root){
            this->del_merge(this->root);
        }
        else if(prev->left == node){
            this->del_merge(prev->left);
        }
        else if(prev->right == node){
            this->del_merge(prev->right);
        }
        else {
            return false;
        }
    }
    return true;
}

template <class T>
const bool BinarySearchTree<T>::del_copy(BSTN<T> * &bstn){
    BSTN<T> * tmp = bstn,
    * prev = NULL;
    
    if(bstn == NULL) {
        return true;
    }
    
    if(bstn->right == NULL){
        bstn = bstn->left;
    }
    else if(bstn->left == NULL){
        bstn = bstn->right;
    }
    else {
        tmp = bstn->left;
        prev = bstn;
        
        while(tmp->right != NULL){
            prev = tmp;
            tmp = tmp->right;
        }
        
        bstn->data = tmp->data;
        
        if(prev == bstn){
            prev->left = tmp->left;
        }
        else {
            prev->right = tmp->left;
        }
    }
    delete tmp;
    return true;
}

template <class T>
const bool BinarySearchTree<T>::find_and_del_by_copy(const T data){
    BSTN<T> * node = this->root,
            * prev = NULL;
    while(node != NULL){
        if(node->data == data){
            break;
        }
        prev = node;
        
        if(node->data < data){
            node = node->right;
        }
        else{
            node = node->left;
        }
    }
    if(node != 0 && node->data == data) {
        if(node == this->root){
            this->del_copy(this->root);
        }
        else if(prev->left == node) {
            this->del_copy(prev->left);
        }
        else if(prev->right == node) {
            this->del_copy(prev->right);
        }
        else{
            return false;
        }
    }
    return true;
}

template <class T>
const bool BinarySearchTree<T>::Delete(const T data){
    this->find_and_del_by_copy(data);
    return true;
}

template <class T>
const bool BinarySearchTree<T>::insert(BSTN<T> * bstn, const T data){
    if(search(bstn, data))
        return false;
    if(bstn == NULL) {
        bstn = new BSTN<T>(data);
        bstn->data = data;
        if(this->root == NULL){
            this->root = bstn;
        }
        return true;
    }
    else{
        BSTN<T> * tmp = NULL;
        while(bstn != NULL){
            tmp = bstn;
            if(data < bstn->data)
                bstn = bstn->left;
            else if(data > bstn->data)
                bstn = bstn->right;
            else
                return false;
        }
        if(data < tmp->data)
            tmp->left = new BSTN<T>(data);
        else
            tmp->right = new BSTN<T>(data);
        return true;
    }
}

template <class T>
const bool BinarySearchTree<T>::Insert(const T data){
    return this->insert(this->root, data);
}

template <class T>
const int BinarySearchTree<T>::GetHeight() const{
    return get_height(this->root);
}

template <class T>
const int BinarySearchTree<T>::GetLeaf() const{
    return get_leaf(this->root);
}

template <class T>
const int BinarySearchTree<T>::GetNodes() const{
    return get_nodes(this->root);
}

// 返回树节点数量
template <class T>
const int BinarySearchTree<T>::get_nodes(BSTN<T> * bstn) const{
    int counter = 0;
    bfs(bstn, [&counter](BSTN<T> * bstn){
        counter++;
        });
    return counter;
}

// 返回树高度
template <class T>
const int BinarySearchTree<T>::get_height(BSTN<T> * bstn) const{
    if (bstn == NULL)
        return 0;
    int lh = get_height(bstn->left);
    int rh = get_height(bstn->right);
    return lh >= rh ? ++lh : ++rh;
}

// 返回叶子结点数量
template <class T>
const int BinarySearchTree<T>::get_leaf(BSTN<T> *bstn) const{
    int counter = 0;
    bfs(bstn, [&counter](BSTN<T> *bstn){
        if(bstn->left == NULL && bstn->right == NULL)
            counter++;
    });
    return counter;
}

template <class T>
void BinarySearchTree<T>::bfs(BSTN<T> *bstn, std::function<void (BSTN<T>*)> fun) const{
    if(bstn != NULL){
        Queue<BSTN<T>*> queue;
        queue.EnQueue(bstn);
        while(!queue.Empty()){
            BSTN<T> * bstn_tmp = queue.DeQueue();
            fun(bstn_tmp);
            if(bstn_tmp->left != NULL)
                queue.EnQueue(bstn_tmp->left);
            if(bstn_tmp->right != NULL)
                queue.EnQueue(bstn_tmp->right);
        }
    }
    return;
}

template <class T>
void BinarySearchTree<T>::dfs_lrv(BSTN<T> *bstn, std::function<void (BSTN<T>*)> fun) const{
    if(bstn != NULL){
        dfs_lrv(bstn->left, fun);
        dfs_lrv(bstn->right, fun);
        fun(bstn);
        return;
    }
    return;
}


template <class T>
void BinarySearchTree<T>::dfs_lvr(BSTN<T> *bstn, std::function<void (BSTN<T>*)> fun) const{
    if(bstn != NULL){
        dfs_lvr(bstn->left, fun);
        fun(bstn);
        dfs_lvr(bstn->right, fun);
        return;
    }
    return;
}

template <class T>
void BinarySearchTree<T>::dfs_vlr(BSTN<T> *bstn, std::function<void (BSTN<T>*)> fun) const{
    if(bstn != NULL){
        fun(bstn);
        dfs_vlr(bstn->left, fun);
        dfs_vlr(bstn->right, fun);
        return;
    }
    return;
}

template <class T>
void BinarySearchTree<T>::balance_dsw(BSTN<T> * bstn){   // DSW 平衡算法
    this->dsw_create_backbone(this->root->left, this->root, NULL);
    this->dsw_recreate_tree(this->root->right, this->root, NULL);
    return;
}

template <class T>
void BinarySearchTree<T>::dsw_create_backbone(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand){
    while(par != NULL) {
        ch = par->left;
        if(ch != NULL) {
            this->bsw_rotate_right(ch, par, grand);
            par = ch;
        }
        else {
            grand = par;
            par = par->right;
        }
    }
    return;
}

template <class T>
void BinarySearchTree<T>::dsw_recreate_tree(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand) {
    int n = this->get_nodes(this->root);
    
    // 节点数目小于3不用平衡
    if(n < 3) {
        return;
    }

    int m = pow(2, ceil(log(n + 1))) - 1;

    this->root = this->root->right; //修改root指针
    // 第一阶段，处理多余节点，左旋n-m次
    for(int i = 0; i < n - m; i++) {
        this->bsw_rotate_left(ch, par, grand);
        grand = ch;
        par = grand->right;
        
        if (par != NULL) {
            ch = par->right;
        } else {
            break;
        }
    }
    
    // 第二阶段，剩余的节点可以组成一颗完全平衡的二叉树
    while(m > 1){
        m /= 2;
        grand = NULL;
        par = this->root;
        ch = this->root->right;
        
        for(int i = 0; i < m; i++) {
            this->bsw_rotate_left(ch, par, grand);
            grand = ch;
            par = grand->right;
            
            if (par != NULL) {
                ch = par->right;
            } else {
                break;
            }
        }
    }
    
    return;
}

template <class T>
void BinarySearchTree<T>::bsw_rotate_right(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand){
    if(grand == NULL){
        this->root = par->left;
    }
    if(grand != NULL) {
        grand->right = ch;
    }
    
    par->left = ch->right;
    ch->right = par;
    return;
}

template <class T>
void BinarySearchTree<T>::bsw_rotate_left(BSTN<T> * ch, BSTN<T> * par, BSTN<T> * grand){
    if(grand == NULL){
        this->root = par->right;
    }
    if(grand != NULL) {
        grand->right = ch;
    }
    
    par->right = ch->left;
    ch->left = par;
    return;
}

template <class T>
const void BinarySearchTree<T>::DisplayTree() const{
    display_tree(this->root);
    return;
}

template <class T>
void BinarySearchTree<T>::display_tree(BSTN<T> * bstn) const{
    std::cout<<"display_tree"<<std::endl;
    
    std::cout<<"root: "<<this->root->data<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"lvr"<<std::endl;
    this->dfs_lvr(bstn, [&](BSTN<T>*bstn){
        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"lrv"<<std::endl;
    this->dfs_lrv(bstn, [&](BSTN<T>*bstn){
        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"bfs"<<std::endl;
    this->bfs(bstn, [&](BSTN<T>*bstn){
        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    return;
}

#endif /* BinarySearchTree_hpp */
