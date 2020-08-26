//
//  BinaryTree.hpp
//  DataStructuer
//
//  Created by NZH on 2020/8/26.
//  Copyright © 2020 Zone.N. All rights reserved.
//

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

// 单纯的二叉树，不包含排序等操作


#include "Queue.hpp"
#include "math.h"

template <class T>
class BSTN {
public:
    BSTN(void);
    BSTN(T data, BSTN<T> * left = nullptr, BSTN<T> * right = nullptr);
    virtual ~BSTN(void);
    T data;
    BSTN<T> * left;
    BSTN<T> * right;
    virtual bool operator >(const BSTN &bstn);
    virtual bool operator <(const BSTN &bstn);
    virtual bool operator ==(const BSTN &bstn);
    virtual bool operator !=(const BSTN &bstn);
    virtual bool operator >=(const BSTN &bstn);
    virtual bool operator <=(const BSTN &bstn);
};

template <class T>
BSTN<T>::BSTN() : data(nullptr), left(nullptr), right(nullptr) {
    return;
}

template <class T>
BSTN<T>::BSTN(T data, BSTN<T> * left, BSTN<T> * right) : data(data), left(left), right(right) {
    return;
}

template <class T>
BSTN<T>::~BSTN() {
    left = nullptr;
    right = nullptr;
    return;
}

template <class T>
bool BSTN<T>::operator >(const BSTN &bstn) {
    return this->data > bstn.data;
}

template <class T>
bool BSTN<T>::operator <(const BSTN &bstn) {
    return this->data < bstn.data;
}

template <class T>
bool BSTN<T>::operator ==(const BSTN &bstn) {
    return this->data > bstn.data;
}

template <class T>
bool BSTN<T>::operator !=(const BSTN &bstn) {
    return this->data > bstn.data;
}

template <class T>
bool BSTN<T>::operator >=(const BSTN &bstn) {
    return this->data > bstn.data;
}

template <class T>
bool BSTN<T>::operator <=(const BSTN &bstn) {
    return this->data > bstn.data;
}

template <class T, template <class> class N = BSTN>
class BinaryTree {
protected:
    // 保存树根节点
    N<T> * root;
    // 插入 ok
    virtual const bool insert(N<T> * bstn, const T data);
    // 合并删除 ok
    virtual const bool del_merge(N<T> * bstn, N<T> * par);
    // 查找并合并删除 ok
    virtual const bool find_and_del_by_merge(const T data);
    // 复制删除 ok
    virtual const bool del_copy(N<T> * &bstn);
    // 查找并复制删除 ok
    virtual const bool find_and_del_by_copy(const T data);
    // 删除以指定节点为根的树 ok
    virtual const bool clean(N<T> * bstn);
    // 返回包含指定数据的节点
    virtual N<T> * get_node(N<T> * bstn, const T data) const;
    // 返回包含指定数据的节点的父节点
    virtual N<T> * get_node_prev(N<T> * bstn, const T data) const;

    // 广度优先遍历 ok
    void bfs(N<T> * bstn, std::function<void (N<T> *)> fun) const;
    // VLR 遍历 ok
    void dfs_vlr(N<T> * bstn, std::function<void (N<T> *)> fun) const;
    // LVR 遍历 ok
    void dfs_lvr(N<T> * bstn, std::function<void (N<T> *)> fun) const;
    // LRV 遍历 ok
    void dfs_lrv(N<T> * bstn, std::function<void (N<T> *)> fun) const;

    // 打印树结构 ok
    virtual void display_tree(N<T> * bstn) const;
    // Internal Path Length 内部路径长度
    const int ipl(N<T> * bstn) const;
    // 返回指定树的树高 ok
    virtual const int get_height(N<T> * bstn) const;
    // 返回以指定节点为根的树的叶子结点数量 ok
    virtual const int get_leaves(N<T> * bstn) const;
    // 返回以指定节点为根的树的结点数量 ok
    virtual const int get_nodes(N<T> * bstn) const;
    // 在指定子树中搜索 data ok
    virtual const bool search(N<T> * bstn, const T data) const;

public:
    BinaryTree(void);
    BinaryTree(const T data);
    BinaryTree(const T * arr, const size_t begin, const size_t end);
    virtual ~BinaryTree(void);

    // 搜索 data ok
    virtual const bool Search(const T data) const;
    // 插入 ok
    virtual const bool Insert(const T data);
    // 删除 ok
    virtual const bool Delete(const T data);
    // 返回是否为空 ok
    virtual const bool Empty(void) const;
    // 返回树高
    virtual const int GetHeight(void) const;
    // 返回树叶子节点数量
    virtual const int GetLeaves(void) const;
    // 返回树节点数量
    virtual const int GetNodes(void) const;
    // 打印树结构
    virtual void Display(void) const;
    // 转换为数组
    virtual const size_t ToArrayLVR(T arr[]) const;
    virtual const size_t ToArrayLRV(T arr[]) const;
    virtual const size_t ToArrayBFS(T arr[]) const;
    // 转换为 vector
    virtual const size_t ToVectorLVR(std::vector<T> &vect) const;
    virtual const size_t ToVectorLRV(std::vector<T> &vect) const;
    virtual const size_t ToVectorBFS(std::vector<T> &vect) const;

};

template <class T, template <class> class N>
BinaryTree<T, N>::BinaryTree(void) : root(nullptr) {
    return;
}

template <class T, template <class> class N>
BinaryTree<T, N>::BinaryTree(const T data) : root(new N<T>(data) ) {
    return;
}

template <class T, template <class> class N>
BinaryTree<T, N>::BinaryTree(const T * arr, const size_t begin, const size_t end) {
    size_t mid = (begin + end) / 2;

    if(begin <= end) {
        this->insert(this->root, arr[mid]);
        this->array_to_bst(arr, begin, mid - 1);
        this->array_to_bst(arr, mid + 1, end);
    }

    return;
}

template <class T, template <class> class N>
BinaryTree<T, N>::~BinaryTree(void) {
    this->clean(this->root);
    return;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::clean(N<T> * bstn) {
    if(bstn != nullptr) {
        if(bstn != this->root) {
            N<T> * node = this->root,
                * prev = nullptr;
            while(node != nullptr) {
                if(node == bstn) {
                    break;
                }
                prev = node;
                if(node->data < bstn->data) {
                    node = node->right;
                } else {
                    node = node->left;
                }
            }
            if(bstn == prev->left) {
                prev->left = nullptr;
            }
            else {
                prev->right = nullptr;
            }
        }
        clean(bstn->left);
        clean(bstn->right);
        delete bstn;
        return true;
    }
    else {
        return false;
    }
}

template <class T, template <class> class N>
const int BinaryTree<T, N>::ipl(N<T> * bstn) const {
    int ipl = 0;
    // TODO
    return ipl;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::Search(const T data) const {
    return search(this->root, data);
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::search(N<T> * bstn, const T data) const {
    if(bstn == nullptr) {
        return false;
    }
    if(data < bstn->data) {
        return search(bstn->left, data);
    }
    else if(data > bstn->data) {
        return search(bstn->right, data);
    }
    else {
        // 找到了，返回对应节点指针。
        return true;
    }
}

template <class T, template <class> class N>
N<T> * BinaryTree<T, N>::get_node(N<T> * bstn, const T data) const {
    N<T> * node = bstn,
        * prev = nullptr;
    while(node != nullptr) {
        if(node->data == data) {
            break;
        }
        prev = node;
        if(node->data < data) {
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return node;
}

template <class T, template <class> class N>
N<T> * BinaryTree<T, N>::get_node_prev(N<T> * bstn, const T data) const {
//    Stack<N<T> *> stack;
//    N<T> * par = nullptr;
//    N<T> * node = this->root;
//    // 节点不为空或栈不为空
//    while(node || stack.Empty() == false) {
//        // 节点不为空时
//        if(node) {
//            // 根节点
//            if((node != nullptr) && (node->data == data)) {
//                break;
//            }
//            // 如果左子节点符合要求
//            else if((node->left != nullptr) && (node->left->data == data)) {
//                par = node;
//                node = node->left;
//                break;
//            }
//            // 如果右子节点符合要求
//            else if((node->left != nullptr) && (node->right->data == data)) {
//                par = node;
//                node = node->right;
//                break;
//            }
//            // 都不符合
//            // 将当前节点入栈
//            // node 指向左子节点
//            else {
//                stack.Push(node);
//                node = node->left;
//            }
//        }
//        // 节点为空
//        else {
//            // 将上一个节点出栈
//            node = stack.Pop();
//            node = node->right;
//        }
//    }
    N<T> * node = bstn,
        * prev = nullptr;
    while(node != nullptr) {
        if(node->data == data) {
            break;
        }
        prev = node;
        if(node->data < data) {
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return prev;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::Empty(void) const {
    return this->root == nullptr;
}

// 合并删除
// 将删除后剩下的子树合并成一棵树
// 需要相应节点的父节点
template <class T, template <class> class N>
const bool BinaryTree<T, N>::del_merge(N<T> * bstn, N<T> * par) {
    if(bstn == nullptr) {
        return false;
    }
    // 首先处理左右子树
    N<T> * node = bstn;
    // 左子树为空
    if(node->left == nullptr) {
        node = node->right;
    }
    // 右子树为空
    else if(node->right == nullptr) {
        node = node->left;
    }
    // 左右子树都不为空
    // 合并两颗子树
    else {
        node = bstn->left;
        while(node->right != nullptr) {
            node = node->right;
        }
        node->right = bstn->right;
        node = bstn;
        bstn = bstn->left;
    }
    // 处理父节点
    if(par == nullptr) {
        this->root = node;
    }
    else if((par->left != nullptr) && (par->left == node)) {
        par->left = bstn;
        std::cout<<"par->left->data: "<< par->left->data<<std::endl;
    }
    else if((par->right != nullptr) && (par->left == node)) {
        par->right = bstn;
        std::cout<<"par->right->data: "<< par->right->data<<std::endl;
    }
    delete bstn;
    return true;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::find_and_del_by_merge(const T data) {
    return del_merge(get_node(this->root, data), get_node_prev(this->root, data));
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::del_copy(N<T> * &bstn) {
    return true;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::find_and_del_by_copy(const T data) {
    return true;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::Delete(const T data) {
    this->find_and_del_by_merge(data);
    return true;
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::insert(N<T> * bstn, const T data) {
    if(this->search(bstn, data) ) {
        return false;
    }
    if(bstn == nullptr) {
        bstn = new N<T>(data);
        bstn->data = data;
        if(this->root == nullptr) {
            this->root = bstn;
        }
        return true;
    }
    else {
        N<T> * tmp = nullptr;
        while(bstn != nullptr) {
            tmp = bstn;
            if(data < bstn->data) {
                bstn = bstn->left;
            }
            else if(data > bstn->data) {
                bstn = bstn->right;
            }
            else {
                return false;
            }
        }
        if(data < tmp->data) {
            tmp->left = new N<T>(data);
        }
        else {
            tmp->right = new N<T>(data);
        }
        return true;
    }
}

template <class T, template <class> class N>
const bool BinaryTree<T, N>::Insert(const T data) {
    return this->insert(this->root, data);
}

template <class T, template <class> class N>
const int BinaryTree<T, N>::GetHeight() const {
    return get_height(this->root);
}

template <class T, template <class> class N>
const int BinaryTree<T, N>::GetLeaves() const {
    return get_leaves(this->root);
}

template <class T, template <class> class N>
const int BinaryTree<T, N>::GetNodes() const {
    return get_nodes(this->root);
}

// 返回树节点数量
template <class T, template <class> class N>
const int BinaryTree<T, N>::get_nodes(N<T> * bstn) const {
    int counter = 0;
    bfs(bstn, [&counter](N<T> * bstn) {
        counter++;
    });
    return counter;
}

// 返回树高度
template <class T, template <class> class N>
const int BinaryTree<T, N>::get_height(N<T> * bstn) const {
    if(bstn == nullptr) {
        return 0;
    }
    int lh = get_height(bstn->left);
    int rh = get_height(bstn->right);
    return lh >= rh ? ++lh : ++rh;
}

// 返回叶子结点数量
template <class T, template <class> class N>
const int BinaryTree<T, N>::get_leaves(N<T> * bstn) const {
    int counter = 0;
    bfs(bstn, [&counter](N<T> * bstn) {
        if(bstn->left == nullptr && bstn->right == nullptr) {
            counter++;
        }
    });
    return counter;
}

template <class T, template <class> class N>
void BinaryTree<T, N>::bfs(N<T> * bstn, std::function<void (N<T> *)> fun) const {
    if(bstn != nullptr) {
        Queue<N<T> *> queue;
        queue.EnQueue(bstn);
        while(!queue.Empty() ) {
            N<T> * bstn_tmp = queue.DeQueue();
            fun(bstn_tmp);
            if(bstn_tmp->left != nullptr) {
                queue.EnQueue(bstn_tmp->left);
            }
            if(bstn_tmp->right != nullptr) {
                queue.EnQueue(bstn_tmp->right);
            }
        }
    }
    return;
}

template <class T, template <class> class N>
void BinaryTree<T, N>::dfs_lrv(N<T> * bstn, std::function<void (N<T> *)> fun) const {
    if(bstn != nullptr) {
        dfs_lrv(bstn->left, fun);
        dfs_lrv(bstn->right, fun);
        fun(bstn);
        return;
    }
    return;
}


template <class T, template <class> class N>
void BinaryTree<T, N>::dfs_lvr(N<T> * bstn, std::function<void (N<T> *)> fun) const {
    if(bstn != nullptr) {
        dfs_lvr(bstn->left, fun);
        fun(bstn);
        dfs_lvr(bstn->right, fun);
        return;
    }
    return;
}

template <class T, template <class> class N>
void BinaryTree<T, N>::dfs_vlr(N<T> * bstn, std::function<void (N<T> *)> fun) const {
    if(bstn != nullptr) {
        fun(bstn);
        dfs_vlr(bstn->left, fun);
        dfs_vlr(bstn->right, fun);
        return;
    }
    return;
}

template <class T, template <class> class N>
void BinaryTree<T, N>::Display() const {
    display_tree(this->root);
    return;
}

template <class T, template <class> class N>
void BinaryTree<T, N>::display_tree(N<T> * bstn) const {
    std::cout << "display_tree" << std::endl;

    if(this->root != nullptr)
        std::cout << "root: " << this->root->data << std::endl;

    std::cout << std::endl;

    std::cout << "lvr" << std::endl;
    this->dfs_lvr(bstn, [&](N<T> * bstn) {
        std::cout << bstn->data << std::endl;
    });

    std::cout << std::endl;

    std::cout << "lrv" << std::endl;
    this->dfs_lrv(bstn, [&](N<T> * bstn) {
        std::cout << bstn->data << std::endl;
    });

    std::cout << std::endl;

    std::cout << "bfs" << std::endl;
    this->bfs(bstn, [&](N<T> * bstn) {
        std::cout << bstn->data << std::endl;
    });

    std::cout << std::endl;

    return;
}

template <class T, template <class> class N>
const size_t BinaryTree<T, N>::ToArrayLVR(T arr[]) const {
    size_t i = 0;
    this->dfs_lvr(this->root, [&](N<T> * bstn) {
        arr[i] = bstn->data;
        i++;
    });
    return i;
}

template <class T, template <class> class N>
const size_t BinaryTree<T, N>::ToArrayLRV(T arr[]) const {
    size_t i = 0;
    this->dfs_lrv(this->root, [&](N<T> * bstn) {
        arr[i] = bstn->data;
        i++;
    });
    return i;
}

template <class T, template <class> class N>
const size_t BinaryTree<T, N>::ToArrayBFS(T arr[]) const {
    size_t i = 0;
    this->bfs(this->root, [&](N<T> * bstn) {
        arr[i] = bstn->data;
        i++;
    });
    return i;
}

template <class T, template <class> class N>
const size_t BinaryTree<T, N>::ToVectorLVR(std::vector<T> &vect) const {
    size_t i = 0;
    this->dfs_lvr(this->root, [&](N<T> * bstn) {
        vect.push_back(bstn->data);
        i++;
    });
    return i;
}

template <class T, template <class> class N>
const size_t BinaryTree<T, N>::ToVectorLRV(std::vector<T> &vect) const {
    size_t i = 0;
    this->dfs_lrv(this->root, [&](N<T> * bstn) {
        vect.push_back(bstn->data);
        i++;
    });
    return i;
}

template <class T, template <class> class N>
const size_t BinaryTree<T, N>::ToVectorBFS(std::vector<T> &vect) const {
    size_t i = 0;
    this->bfs(this->root, [&](N<T> * bstn) {
        vect.push_back(bstn->data);
        i++;
    });
    return i;
}

#endif /* BINARYTREE_HPP */
