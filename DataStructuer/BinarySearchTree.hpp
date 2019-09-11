//
//  BinarySearchTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2018/10/29.
//  Copyright © 2018 Zone.N. All rights reserved.
//

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Queue.hpp"
#include "math.h"

template <class T>
class BSTN {
public:
    T data;
    BSTN<T> * left;
    BSTN<T> * right;
    BSTN(void);
    BSTN(T data, BSTN<T> * left = NULL, BSTN<T> * right = NULL);
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

template <class T, template<class> class N = BSTN>
class BinarySearchTree {
protected:
    N<T> * root; // 保存树根节点
    
    virtual const bool insert(N<T> * bstn, const T data);  // 插入 ok
    virtual const bool del_merge(N<T> * &bstn);    // 合并删除 ok
    virtual const bool find_and_del_by_merge(const T data); // ok
    virtual const bool del_copy(N<T> * &bstn);    // 复制删除 ok
    virtual const bool find_and_del_by_copy(const T data); // ok
    virtual const bool clean(N<T> * bstn);  // 删除以指定节点为根的树 ok
    virtual N<T> * get_node(const T data) const; // 返回包含指定数据的节点
    virtual N<T> * get_node_prev(const T data) const; // 返回包含指定数据的节点的父节点
    
    void bfs(N<T> *bstn, std::function<void (N<T>*)> fun) const;  // 广度优先遍历 ok
    void dfs_vlr(N<T> * bstn, std::function<void (N<T>*)> fun) const; // VLR 遍历 ok
    void dfs_lvr(N<T> * bstn, std::function<void (N<T>*)> fun) const; // LVR 遍历 ok
    void dfs_lrv(N<T> * bstn, std::function<void (N<T>*)> fun) const; // LRV 遍历 ok
    
    void balance_dsw(N<T> * bstn);   // DSW 平衡算法 ok
    void dsw_create_backbone(N<T> * ch, N<T> * bstn, N<T> * par); // dsw 算法，创建主链 ok
    void dsw_recreate_tree(N<T> * ch, N<T> * par, N<T> * grand);   // dsw 算法，重新生成树 ok
    virtual void rotate_right(N<T> * ch, N<T> * par, N<T> * grand); // 右旋 ok
    virtual void rotate_left(N<T> * ch, N<T> * par, N<T> * grand); // 左旋 ok
    
    virtual void display_tree(N<T> * bstn) const; // 打印树结构 ok
    const int ipl(N<T> * bstn) const; // Internal Path Length 内部路径长度
    virtual const int get_height(N<T> * bstn) const; // 返回指定树的树高 ok
    virtual const int get_leaf(N<T> * bstn) const;  // 返回以指定节点为根的树的叶子结点数量 ok
    virtual const int get_nodes(N<T> * bstn) const;    // 返回以指定节点为根的树的结点数量 ok
    virtual const bool search(N<T> * bstn, const T data) const;   // 在指定子树中搜索 data ok
    
public:
    BinarySearchTree(void);
    BinarySearchTree(const T data);
    BinarySearchTree(const T * arr, const size_t begin, const size_t end);
    virtual ~BinarySearchTree(void);
    
    virtual const bool Search(const T data) const;   // 搜索 data ok
    virtual const bool Insert(const T data);  // 插入 ok
    virtual const bool Delete(const T data);   // 删除 ok
    
    virtual const bool Empty(void) const; // 返回是否为空 ok
    virtual const int GetHeight(void) const;  // 返回树高
    virtual const int GetLeaf(void) const;  // 返回树叶子节点数量
    virtual const int GetNodes(void) const;   // 返回树节点数量
    virtual void DisplayTree(void) const;   // 打印树结构
    
};

template <class T, template<class> class N>
BinarySearchTree<T, N>::BinarySearchTree(void){
    this->root = NULL;
    return;
}

template <class T, template<class> class N>
BinarySearchTree<T, N>::BinarySearchTree(const T data){
    this->root = new N<T>(data);
    this->root->data = data;
    return;
}

template <class T, template<class> class N>
BinarySearchTree<T, N>::BinarySearchTree(const T * arr, const size_t begin, const size_t end) {
    size_t mid = (begin + end) / 2;
    
    if(begin <= end){
        this->insert(this->root, arr[mid]);
        this->array_to_bst(arr, begin, mid - 1);
        this->array_to_bst(arr, mid + 1, end);
    }
    
    return;
}

template <class T, template<class> class N>
BinarySearchTree<T, N>::~BinarySearchTree(void){
    this->clean(this->root);
    return;
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::clean(N<T> * bstn){
    if(bstn != NULL){
        if(bstn != this->root){
            N<T> * node = this->root,
                 * prev = NULL;
            while(node != NULL) {
                if(node == bstn){
                    break;
                }
                prev = node;
                if(node->data < bstn->data) {
                    node = node->right;
                } else {
                    node = node->left;
                }
            }
            if(bstn == prev->left){
                prev->left = NULL;
            }
            else {
                prev->right = NULL;
            }
        }
        clean(bstn->left);
        clean(bstn->right);
        delete bstn;
        return true;
    }
    else{
        return false;
    }
}

template <class T, template<class> class N>
const int BinarySearchTree<T, N>::ipl(N<T> * bstn) const{
    int ipl = 0;
    // TODO
    return ipl;
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::Search(const T data) const{
    return search(this->root, data);
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::search(N<T> * bstn, const T data) const{
    if(bstn == NULL)  return false;
    if(data < bstn->data)
        return search(bstn->left, data);
    else if(data > bstn->data)
        return search(bstn->right, data);
    else
        return true;    // 找到了，返回对应节点指针。
}

template <class T, template<class> class N>
N<T> * BinarySearchTree<T, N>::get_node(const T data) const{
    N<T> * node = this->root,
         * prev = NULL;
    while(node != NULL){
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
    return node;
}

template <class T, template<class> class N>
N<T> * BinarySearchTree<T, N>::get_node_prev(const T data) const{
    N<T> * node = this->root,
         * prev = NULL;
    while(node != NULL){
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
    return prev;
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::Empty(void) const{
    return this->root == NULL;
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::del_merge(N<T> * &bstn){
    N<T> * tmp = bstn;
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

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::find_and_del_by_merge(const T data){
    N<T> * node = this->get_node(data),
         * prev = this->get_node_prev(data);
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

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::del_copy(N<T> * &bstn){
    N<T> * tmp = bstn,
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

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::find_and_del_by_copy(const T data){
    N<T> * node = this->get_node(data),
         * prev = this->get_node_prev(data);
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

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::Delete(const T data){
    this->find_and_del_by_copy(data);
    return true;
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::insert(N<T> * bstn, const T data){
    if(search(bstn, data))
        return false;
    if(bstn == NULL) {
        bstn = new N<T>(data);
        bstn->data = data;
        if(this->root == NULL){
            this->root = bstn;
        }
        return true;
    }
    else{
        N<T> * tmp = NULL;
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
            tmp->left = new N<T>(data);
        else
            tmp->right = new N<T>(data);
        return true;
    }
}

template <class T, template<class> class N>
const bool BinarySearchTree<T, N>::Insert(const T data){
    return this->insert(this->root, data);
}

template <class T, template<class> class N>
const int BinarySearchTree<T, N>::GetHeight() const{
    return get_height(this->root);
}

template <class T, template<class> class N>
const int BinarySearchTree<T, N>::GetLeaf() const{
    return get_leaf(this->root);
}

template <class T, template<class> class N>
const int BinarySearchTree<T, N>::GetNodes() const{
    return get_nodes(this->root);
}

// 返回树节点数量
template <class T, template<class> class N>
const int BinarySearchTree<T, N>::get_nodes(N<T> * bstn) const{
    int counter = 0;
    bfs(bstn, [&counter](N<T> * bstn){
        counter++;
        });
    return counter;
}

// 返回树高度
template <class T, template<class> class N>
const int BinarySearchTree<T, N>::get_height(N<T> * bstn) const{
    if (bstn == NULL)
        return 0;
    int lh = get_height(bstn->left);
    int rh = get_height(bstn->right);
    return lh >= rh ? ++lh : ++rh;
}

// 返回叶子结点数量
template <class T, template<class> class N>
const int BinarySearchTree<T, N>::get_leaf(N<T> *bstn) const{
    int counter = 0;
    bfs(bstn, [&counter](N<T> *bstn){
        if(bstn->left == NULL && bstn->right == NULL)
            counter++;
    });
    return counter;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::bfs(N<T> *bstn, std::function<void (N<T>*)> fun) const{
    if(bstn != NULL){
        Queue<N<T>*> queue;
        queue.EnQueue(bstn);
        while(!queue.Empty()){
            N<T> * bstn_tmp = queue.DeQueue();
            fun(bstn_tmp);
            if(bstn_tmp->left != NULL)
                queue.EnQueue(bstn_tmp->left);
            if(bstn_tmp->right != NULL)
                queue.EnQueue(bstn_tmp->right);
        }
    }
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::dfs_lrv(N<T> *bstn, std::function<void (N<T>*)> fun) const{
    if(bstn != NULL){
        dfs_lrv(bstn->left, fun);
        dfs_lrv(bstn->right, fun);
        fun(bstn);
        return;
    }
    return;
}


template <class T, template<class> class N>
void BinarySearchTree<T, N>::dfs_lvr(N<T> *bstn, std::function<void (N<T>*)> fun) const{
    if(bstn != NULL){
        dfs_lvr(bstn->left, fun);
        fun(bstn);
        dfs_lvr(bstn->right, fun);
        return;
    }
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::dfs_vlr(N<T> *bstn, std::function<void (N<T>*)> fun) const{
    if(bstn != NULL){
        fun(bstn);
        dfs_vlr(bstn->left, fun);
        dfs_vlr(bstn->right, fun);
        return;
    }
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::balance_dsw(N<T> * bstn){   // DSW 平衡算法
    this->dsw_create_backbone(this->root->left, this->root, NULL);
    this->dsw_recreate_tree(this->root->right, this->root, NULL);
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::dsw_create_backbone(N<T> * ch, N<T> * par, N<T> * grand){
    while(par != NULL) {
        ch = par->left;
        if(ch != NULL) {
            this->rotate_right(ch, par, grand);
            par = ch;
        }
        else {
            grand = par;
            par = par->right;
        }
    }
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::dsw_recreate_tree(N<T> * ch, N<T> * par, N<T> * grand) {
    int n = this->get_nodes(this->root);
    
    // 节点数目小于 3 不用平衡
    if(n < 3) {
        return;
    }

    int m = pow(2, ceil(log(n + 1))) - 1;

    // 修改 root 指针
    this->root = this->root->right;
    
    // 第一阶段，处理多余节点，左旋 n-m 次
    for(int i = 0; i < n - m; i++) {
        this->rotate_left(ch, par, grand);
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
            this->rotate_left(ch, par, grand);
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

template <class T, template<class> class N>
void BinarySearchTree<T, N>::rotate_right(N<T> * ch, N<T> * par, N<T> * grand){
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

template <class T, template<class> class N>
void BinarySearchTree<T, N>::rotate_left(N<T> * ch, N<T> * par, N<T> * grand){
    if(grand == NULL){
        this->root = par->right;
    }
    if(grand != NULL) {
        grand->left = ch;
    }
    
    par->right = ch->left;
    ch->left = par;
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::DisplayTree() const{
    display_tree(this->root);
    return;
}

template <class T, template<class> class N>
void BinarySearchTree<T, N>::display_tree(N<T> * bstn) const{
    std::cout<<"display_tree"<<std::endl;
    
    if(this->root != NULL)
        std::cout<<"root: "<<this->root->data<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"lvr"<<std::endl;
    this->dfs_lvr(bstn, [&](N<T>*bstn){
        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"lrv"<<std::endl;
    this->dfs_lrv(bstn, [&](N<T>*bstn){
        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"bfs"<<std::endl;
    this->bfs(bstn, [&](N<T>*bstn){
        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    return;
}

#endif /* BINARYSEARCHTREE_HPP */
