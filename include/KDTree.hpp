//
//  k-dTree.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef KDTREE_HPP
#define KDTREE_HPP

#include "BinarySearchTree.hpp"

// KDTree 节点
template <size_t K = 2, class T = std::string>
class KDTN {
public:
    T data[K];
    KDTN<K, T> * left;
    KDTN<K, T> * right;
    KDTN(void);
    KDTN(T * data, size_t k);
    virtual ~KDTN(void);
};

template <size_t K, class T>
KDTN<K, T>::KDTN() : data{}, left(nullptr), right(nullptr) {
    return;
}

template <size_t K, class T>
KDTN<K, T>::KDTN(T * data, size_t k) : data{}, left(nullptr), right(nullptr) {
    memcpy(this->data, data, k * sizeof(T) );
    // static_assert(k != K, "k != K");
    return;
}

template <size_t K, class T>
KDTN<K, T>::~KDTN() {
    delete left;
    delete right;
    return;
}

// KDTree
template <size_t K = 2, class T = std::string, template <size_t, class> class N = KDTN>
class KDTree {
private:
    N<K, T> * root;

    virtual const bool insert(N<K, T> * kdtn, const T data);  // 插入 ok
    //    virtual const bool del_merge(N<K, T> * kdtn, N<K, T> * par);    // 合并删除 ok
    //    virtual const bool find_and_del_by_merge(const T data); // ok
    //    virtual const bool del_copy(N<K, T> * &btn);    // 复制删除 ok
    //    virtual const bool find_and_del_by_copy(const T data); // ok
    virtual const bool search(N<K, T> * kdtn, const T data) const;   // 在指定子树中搜索 data ok
    virtual const bool clean(N<K, T> * kdtn);  // 删除以指定节点为根的树 ok
    virtual N<K, T> * get_node(N<K, T> * kdtn, const T data) const; // 返回包含指定数据的节点
    virtual N<K, T> * get_node_prev(N<K, T> * kdtn, const T data) const; // 返回包含指定数据的节点的父节点

    void bfs(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const;  // 广度优先遍历 ok
    void dfs_vlr(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const; // VLR 遍历 ok
    void dfs_lvr(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const; // LVR 遍历 ok
    void dfs_lrv(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const; // LRV 遍历 ok

    const int ipl(N<K, T> * kdtn) const; // Internal Path Length 内部路径长度
    virtual const int get_height(N<K, T> * kdtn) const; // 返回指定树的树高 ok
    virtual const int get_leaves(N<K, T> * kdtn) const;  // 返回以指定节点为根的树的叶子结点数量 ok
    virtual const int get_nodes(N<K, T> * kdtn) const;    // 返回以指定节点为根的树的结点数量 ok
    virtual void display_tree(N<K, T> * kdtn) const; // 打印树结构 ok

public:
    KDTree(void);
    KDTree(T * data, size_t k);
    virtual ~KDTree(void);

    virtual const bool Search(const T data) const;   // 搜索 data ok
    virtual const bool Insert(const T data);  // 插入 ok
    virtual const bool Delete(const T data);   // 删除 ok

    virtual const bool Empty(void) const; // 返回是否为空 ok
    virtual const int GetHeight(void) const;  // 返回树高
    virtual const int GetLeaf(void) const;  // 返回树叶子节点数量
    virtual const int GetNodes(void) const;   // 返回树节点数量
    virtual void DisplayTree(void) const;   // 打印树结构
};

template <size_t K, class T, template <size_t, class> class N>
KDTree<K, T, N>::KDTree() : root(nullptr) {
    return;
}

template <size_t K, class T, template <size_t, class> class N>
KDTree<K, T, N>::KDTree(T data[], size_t k) : root(new N<K, T>(data, k) ) {
    return;
}

template <size_t K, class T, template <size_t, class> class N>
KDTree<K, T, N>::~KDTree() {
    return;
}


template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::Search(const T data) const {
    return search(this->root, data);
}

template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::Insert(const T data) {
    return this->insert(this->root, data);
}

template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::Delete(const T data) {
    return true;
}

template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::Empty(void) const {
    return this->root == nullptr;
}

template <size_t K, class T, template <size_t, class> class N>
const int KDTree<K, T, N>::GetHeight() const {
    return get_height(this->root);
}

template <size_t K, class T, template <size_t, class> class N>
const int KDTree<K, T, N>::GetLeaf() const {
    return get_leaves(this->root);
}

template <size_t K, class T, template <size_t, class> class N>
const int KDTree<K, T, N>::GetNodes() const {
    return get_nodes(this->root);
}

template <size_t K, class T, template <size_t, class> class N>
void KDTree<K, T, N>::DisplayTree() const {
    display_tree(this->root);
    return;
}

template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::insert(N<K, T> * kdtn, const T data) {
    return true;
}

template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::search(N<K, T> * kdtn, const T data) const {
    //    if(kdtn == nullptr)  return false;
    //    if(data < kdtn->data)
    //        return search(kdtn->left, data);
    //    else if(data > kdtn->data)
    //        return search(kdtn->right, data);
    //    else
    return true;    // 找到了，返回对应节点指针。
}

template <size_t K, class T, template <size_t, class> class N>
const bool KDTree<K, T, N>::clean(N<K, T> * kdtn) {
    if(kdtn != nullptr) {
        if(kdtn != this->root) {
            N<K, T> * node = this->root,
                * prev = nullptr;
            while(node != nullptr) {
                if(node == kdtn) {
                    break;
                }
                prev = node;
                //                if(node->data < kdtn->data) {
                //                    node = node->right;
                //                } else {
                //                    node = node->left;
                //                }
            }
            if(kdtn == prev->left) {
                prev->left = nullptr;
            }
            else {
                prev->right = nullptr;
            }
        }
        clean(kdtn->left);
        clean(kdtn->right);
        delete kdtn;
        return true;
    }
    else {
        return false;
    }
}

template <size_t K, class T, template <size_t, class> class N>
N<K, T> *  KDTree<K, T, N>::get_node(N<K, T> * kdtn, const T data) const {
    N<K, T> * node = kdtn,
        * prev = nullptr;
    while(node != nullptr) {
        //        if(node->data == data){
        //            break;
        //        }
        prev = node;
        //        if(node->data < data) {
        //            node = node->right;
        //        } else {
        //            node = node->left;
        //        }
    }
    return node;
}

template <size_t K, class T, template <size_t, class> class N>
N<K, T> *  KDTree<K, T, N>::get_node_prev(N<K, T> * kdtn, const T data) const {
    N<K, T> * node = kdtn,
        * prev = nullptr;
    while(node != nullptr) {
        //        if(node->data == data){
        //            break;
        //        }
        prev = node;
        //        if(node->data < data) {
        //            node = node->right;
        //        } else {
        //            node = node->left;
        //        }
    }
    return prev;
}

template <size_t K, class T, template <size_t, class> class N>
void KDTree<K, T, N>::bfs(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const {
    if(kdtn != nullptr) {
        Queue<N<K, T> *> queue;
        queue.EnQueue(kdtn);
        while(!queue.Empty() ) {
            N<K, T> * kdtn_tmp = queue.DeQueue();
            fun(kdtn_tmp);
            if(kdtn_tmp->left != nullptr)
                queue.EnQueue(kdtn_tmp->left);
            if(kdtn_tmp->right != nullptr)
                queue.EnQueue(kdtn_tmp->right);
        }
    }
    return;
}

template <size_t K, class T, template <size_t, class> class N>
void KDTree<K, T, N>::dfs_vlr(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const {
    if(kdtn != nullptr) {
        fun(kdtn);
        dfs_vlr(kdtn->left, fun);
        dfs_vlr(kdtn->right, fun);
        return;
    }
    return;
}

template <size_t K, class T, template <size_t, class> class N>
void KDTree<K, T, N>::dfs_lvr(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const {
    if(kdtn != nullptr) {
        dfs_lvr(kdtn->left, fun);
        fun(kdtn);
        dfs_lvr(kdtn->right, fun);
        return;
    }
    return;
}

template <size_t K, class T, template <size_t, class> class N>
void KDTree<K, T, N>::dfs_lrv(N<K, T> * kdtn, std::function<void (N<K, T> *)> fun) const {
    if(kdtn != nullptr) {
        dfs_lrv(kdtn->left, fun);
        dfs_lrv(kdtn->right, fun);
        fun(kdtn);
        return;
    }
    return;
}

// 返回树节点数量
template <size_t K, class T, template <size_t, class> class N>
const int KDTree<K, T, N>::get_nodes(N<K, T> * kdtn) const {
    int counter = 0;
    bfs(kdtn, [&counter](N<K, T> * kdtn) {
        counter++;
    });
    return counter;
}

// 返回树高度
template <size_t K, class T, template <size_t, class> class N>
const int KDTree<K, T, N>::get_height(N<K, T> * kdtn) const {
    if(kdtn == nullptr)
        return 0;
    int lh = get_height(kdtn->left);
    int rh = get_height(kdtn->right);
    return lh >= rh ? ++lh : ++rh;
}

// 返回叶子结点数量
template <size_t K, class T, template <size_t, class> class N>
const int KDTree<K, T, N>::get_leaves(N<K, T> * kdtn) const {
    int counter = 0;
    bfs(kdtn, [&counter](N<K, T> * kdtn) {
        if(kdtn->left == nullptr && kdtn->right == nullptr)
            counter++;
    });
    return counter;
}

template <size_t K, class T, template <size_t, class> class N>
void KDTree<K, T, N>::display_tree(N<K, T> * kdtn) const {
    std::cout << "display_tree" << std::endl;

    if(this->root != nullptr) {
        std::cout << "root: ";
        for(auto item:kdtn->data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "lvr" << std::endl;
    this->dfs_lvr(kdtn, [&](N<K, T> * kdtn) {
        for(auto item:kdtn->data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    });
    std::cout << std::endl;

    std::cout << "lrv" << std::endl;
    this->dfs_lrv(kdtn, [&](N<K, T> * kdtn) {
        for(auto item:kdtn->data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    });

    std::cout << std::endl;

    std::cout << "bfs" << std::endl;
    this->bfs(kdtn, [&](N<K, T> * kdtn) {
        for(auto item:kdtn->data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    });

    std::cout << std::endl;

    return;
}


#endif /* KDTREE_HPP */
