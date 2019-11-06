//
//  BTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2019/1/30.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef BTREE_HPP
#define BTREE_HPP

template <class T, size_t M = 50>
class BTN {
public:
    bool leaf;
    size_t key_total;
    T keys[M-1];
    BTN<T, M> * pointers[M];
    
    BTN(void);
    BTN(const T data);
    BTN(const BTN &btn);
    BTN(const BTN &&btn);
    virtual ~BTN(void);
};

template <class T, size_t M>
BTN<T, M>::BTN(void) : leaf(true), key_total(0), keys{}, pointers{} {
    return;
}

template <class T, size_t M>
BTN<T, M>::BTN(const T key) : leaf(true), key_total(1), keys{key, 0}, pointers{} {
    return;
}

template <class T, size_t M>
BTN<T, M>::BTN(const BTN &btn) : leaf(btn.leaf), key_total(btn.key_total), keys(btn.keys), pointers(btn.pointers) {
    delete btn;
    return;
}

template <class T, size_t M>
BTN<T, M>::BTN(const BTN &&btn) : leaf(btn.leaf), key_total(btn.key_total), keys(btn.keys), pointers(btn.pointers) {
    return;
}

template <class T, size_t M>
BTN<T, M>::~BTN(){
    return;
}

template <class T, size_t M = 50, template<class, size_t> class N = BTN>
class BTree {
protected:
    N<T, M> * root; // 保存树根节点
    
    virtual const bool insert(N<T, M> * btn, const T data);  // 插入 ok
//    virtual const bool del_merge(N<T, M> * btn, N<T, M> * par);    // 合并删除 ok
//    virtual const bool find_and_del_by_merge(const T data); // ok
//    virtual const bool del_copy(N<T, M> * &btn);    // 复制删除 ok
//    virtual const bool find_and_del_by_copy(const T data); // ok
    virtual const bool search(N<T, M> * btn, const T data) const;   // 在指定子树中搜索 data ok
    virtual const bool clean(N<T, M> * btn);  // 删除以指定节点为根的树 ok
    virtual N<T, M> * get_node(N<T, M> * btn, const T data) const; // 返回包含指定数据的节点
    virtual N<T, M> * get_node_prev(N<T, M> * btn, const T data) const; // 返回包含指定数据的节点的父节点

    void bfs(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const;  // 广度优先遍历 ok
    void dfs_vlr(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const; // VLR 遍历 ok
    void dfs_lvr(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const; // LVR 遍历 ok
    void dfs_lrv(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const; // LRV 遍历 ok
    
    const int ipl(N<T, M> * btn) const; // Internal Path Length 内部路径长度
    virtual const int get_height(N<T, M> * btn) const; // 返回指定树的树高 ok
    virtual const int get_leaves(N<T, M> * btn) const;  // 返回以指定节点为根的树的叶子结点数量 ok
    virtual const int get_nodes(N<T, M> * btn) const;    // 返回以指定节点为根的树的结点数量 ok
    virtual void display_tree(N<T, M> * btn) const; // 打印树结构 ok
    
public:
    BTree(void);
    BTree(const T data);
    BTree(const BTree &bt); // 复制构造函数
    BTree(BTree &&bt);   // 移动构造函数
    virtual ~BTree(void);
    
    virtual const bool Search(const T data) const;   // 搜索 data ok
    virtual const bool Insert(const T data);  // 插入 ok
    virtual const bool Delete(const T data);   // 删除 ok
    
    virtual const bool Empty(void) const; // 返回是否为空 ok
    virtual const int GetHeight(void) const;  // 返回树高
    virtual const int GetLeaf(void) const;  // 返回树叶子节点数量
    virtual const int GetNodes(void) const;   // 返回树节点数量
    virtual void DisplayTree(void) const;   // 打印树结构
    
};

template <class T, size_t M, template<class, size_t> class N>
BTree<T, M, N>::BTree(void) : root(nullptr){
    return;
}

template <class T, size_t M, template<class, size_t> class N>
BTree<T, M, N>::BTree(const T data) : root(new N<T, M>(data)){
    return;
}

template <class T, size_t M, template<class, size_t> class N>
BTree<T, M, N>::BTree(const BTree &bt) : root(bt.root){
    return;
}

template <class T, size_t M, template<class, size_t> class N>
BTree<T, M, N>::BTree(BTree &&bt) : root(bt.root){
    bt.root = nullptr;
    return;
}

template <class T, size_t M, template<class, size_t> class N>
BTree<T, M, N>::~BTree(void){
    return;
}

template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::Search(const T data) const{
    return search(this->root, data);
}

template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::Insert(const T data){
    return this->insert(this->root, data);
}

template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::Delete(const T data){
    return true;
}


template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::Empty(void) const{
    return this->root == nullptr;
}

template <class T, size_t M, template<class, size_t> class N>
const int BTree<T, M, N>::GetHeight() const{
    return get_height(this->root);
}

template <class T, size_t M, template<class, size_t> class N>
const int BTree<T, M, N>::GetLeaf() const{
    return get_leaves(this->root);
}

template <class T, size_t M, template<class, size_t> class N>
const int BTree<T, M, N>::GetNodes() const{
    return get_nodes(this->root);
}

template <class T, size_t M, template<class, size_t> class N>
void BTree<T, M, N>::DisplayTree() const{
    display_tree(this->root);
    return;
}



template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::insert(N<T, M> * btn, const T data) {
    return true;
}

template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::search(N<T, M> * bstn, const T data) const{
    return true;    // 找到了，返回对应节点指针。
}

template <class T, size_t M, template<class, size_t> class N>
const bool BTree<T, M, N>::clean(N<T, M> * btn) {
    return true;
}

template <class T, size_t M, template<class, size_t> class N>
N<T, M> *  BTree<T, M, N>::get_node(N<T, M> * btn, const T data) const {
    return nullptr;
}

template <class T, size_t M, template<class, size_t> class N>
N<T, M> *  BTree<T, M, N>::get_node_prev(N<T, M> * btn, const T data) const {
    return nullptr;
}

template <class T, size_t M, template<class, size_t> class N>
void BTree<T, M, N>::bfs(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const {
    return;
}

template <class T, size_t M, template<class, size_t> class N>
void BTree<T, M, N>::dfs_vlr(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const {
    return;
}

template <class T, size_t M, template<class, size_t> class N>
void BTree<T, M, N>::dfs_lvr(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const {
    return;
}

template <class T, size_t M, template<class, size_t> class N>
void BTree<T, M, N>::dfs_lrv(N<T, M> * btn, std::function<void (N<T, M>*)> fun) const {
    return;
}

// 返回树节点数量
template <class T, size_t M, template<class, size_t> class N>
const int BTree<T, M, N>::get_nodes(N<T, M> * btn) const{
    return 0;
}

// 返回树高度
template <class T, size_t M, template<class, size_t> class N>
const int BTree<T, M, N>::get_height(N<T, M> * btn) const{
    return 0;
}

// 返回叶子结点数量
template <class T, size_t M, template<class, size_t> class N>
const int BTree<T, M, N>::get_leaves(N<T, M> * btn) const{
    return 0;
}

template <class T, size_t M, template<class, size_t> class N>
void BTree<T, M, N>::display_tree(N<T, M> * btn) const {
    std::cout<<"display_tree"<<std::endl;
    
    if(this->root != nullptr)
//        std::cout<<"root: "<<this->root->data<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"lvr"<<std::endl;
    this->dfs_lvr(btn, [&](N<T, M> * btn){
//        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"lrv"<<std::endl;
    this->dfs_lrv(btn, [&](N<T, M> * btn){
//        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"bfs"<<std::endl;
    this->bfs(btn, [&](N<T, M> * btn){
//        std::cout<<bstn->data<<std::endl;
    });
    
    std::cout<<std::endl;
    
    return;
}

#endif /* BTREE_HPP */
