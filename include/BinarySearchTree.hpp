//
//  BinarySearchTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2018/10/29.
//  Copyright © 2018 Zone.N. All rights reserved.
//

// TODO
// 补齐各种操作的迭代与递归形式，目前计划有这些操作
// insert, search, clean, bfs, dfs, delete by merge

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Queue.hpp"
#include "BinaryTree.hpp"
#include "math.h"

template <class T, template <class> class N = BSTN>
class BinarySearchTree : public BinaryTree<T, N> {
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

    // 平衡树
    void balance(N<T> * bstn);
    // DSW 平衡算法 ok
    void balance_dsw(N<T> * bstn);
    // dsw 算法，创建主链 ok
    void dsw_create_backbone(N<T> * ch, N<T> * bstn, N<T> * par);
    // dsw 算法，重新生成树 ok
    void dsw_recreate_tree(N<T> * ch, N<T> * par, N<T> * grand);
    // 右旋 ok
    virtual void rotate_right(N<T> * ch, N<T> * par, N<T> * grand);
    // 左旋 ok
    virtual void rotate_left(N<T> * ch, N<T> * par, N<T> * grand);
    // 在指定子树中搜索 data ok
    virtual const bool search(N<T> * bstn, const T data) const;

public:
    BinarySearchTree(void);
    BinarySearchTree(const T data);
    BinarySearchTree(const T * arr, const size_t begin, const size_t end);
    virtual ~BinarySearchTree(void);

    // 搜索 data ok
    virtual const bool Search(const T data) const;
    // 插入 ok
    virtual const bool Insert(const T data);
    // 删除 ok
    virtual const bool Delete(const T data);
    // 平衡
    virtual void Balance(void);
};

template <class T, template <class> class N>
BinarySearchTree<T, N>::BinarySearchTree(void) : root(nullptr) {
    return;
}

template <class T, template <class> class N>
BinarySearchTree<T, N>::BinarySearchTree(const T data) : root(new N<T>(data) ) {
    return;
}

template <class T, template <class> class N>
BinarySearchTree<T, N>::BinarySearchTree(const T * arr, const size_t begin, const size_t end) {
    size_t mid = (begin + end) / 2;

    if(begin <= end) {
        this->insert(this->root, arr[mid]);
        this->array_to_bst(arr, begin, mid - 1);
        this->array_to_bst(arr, mid + 1, end);
    }

    return;
}

template <class T, template <class> class N>
BinarySearchTree<T, N>::~BinarySearchTree(void) {
    this->clean(this->root);
    return;
}

template <class T, template <class> class N>
const bool BinarySearchTree<T, N>::clean(N<T> * bstn) {
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
const bool BinarySearchTree<T, N>::search(N<T> * bstn, const T data) const {
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
const bool BinarySearchTree<T, N>::Search(const T data) const {
    return search(this->root, data);
}

template <class T, template <class> class N>
N<T> * BinarySearchTree<T, N>::get_node(N<T> * bstn, const T data) const {
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
N<T> * BinarySearchTree<T, N>::get_node_prev(N<T> * bstn, const T data) const {
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

// 合并删除
// 将删除后剩下的子树合并成一棵树
// 需要相应节点的父节点
template <class T, template <class> class N>
const bool BinarySearchTree<T, N>::del_merge(N<T> * bstn, N<T> * par) {
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
const bool BinarySearchTree<T, N>::find_and_del_by_merge(const T data) {
    return del_merge(get_node(this->root, data), get_node_prev(this->root, data));
}

template <class T, template <class> class N>
const bool BinarySearchTree<T, N>::del_copy(N<T> * &bstn) {
    return true;
}

template <class T, template <class> class N>
const bool BinarySearchTree<T, N>::find_and_del_by_copy(const T data) {
    return true;
}

template <class T, template <class> class N>
const bool BinarySearchTree<T, N>::Delete(const T data) {
    this->find_and_del_by_merge(data);
    return true;
}

template <class T, template <class> class N>
const bool BinarySearchTree<T, N>::insert(N<T> * bstn, const T data) {
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
const bool BinarySearchTree<T, N>::Insert(const T data) {
    return this->insert(this->root, data);
}

template <class T, template <class> class N>
void BinarySearchTree<T, N>::balance(N<T> * bstn) {
    this->balance_dsw(this->root);
    return;
}

template <class T, template <class> class N>
void BinarySearchTree<T, N>::balance_dsw(N<T> * bstn) {   // DSW 平衡算法
    this->dsw_create_backbone(this->root->left, this->root, nullptr);
    this->dsw_recreate_tree(this->root->right, this->root, nullptr);
    return;
}

template <class T, template <class> class N>
void BinarySearchTree<T, N>::dsw_create_backbone(N<T> * ch, N<T> * par, N<T> * grand) {
    while(par != nullptr) {
        ch = par->left;
        if(ch != nullptr) {
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

template <class T, template <class> class N>
void BinarySearchTree<T, N>::dsw_recreate_tree(N<T> * ch, N<T> * par, N<T> * grand) {
    int n = this->get_nodes(this->root);

    // 节点数目小于 3 不用平衡
    if(n < 3) {
        return;
    }

    int m = pow(2, ceil(log(n + 1) ) ) - 1;

    // 修改 root 指针
    this->root = this->root->right;

    // 第一阶段，处理多余节点，左旋 n-m 次
    for(int i = 0 ; i < n - m ; i++) {
        this->rotate_left(ch, par, grand);
        grand = ch;
        par = grand->right;

        if(par != nullptr) {
            ch = par->right;
        }
        else {
            break;
        }
    }

    // 第二阶段，剩余的节点可以组成一颗完全平衡的二叉树
    while(m > 1) {
        m /= 2;
        grand = nullptr;
        par = this->root;
        ch = this->root->right;

        for(int i = 0 ; i < m ; i++) {
            this->rotate_left(ch, par, grand);
            grand = ch;
            par = grand->right;

            if(par != nullptr) {
                ch = par->right;
            }
            else {
                break;
            }
        }
    }

    return;
}

template <class T, template <class> class N>
void BinarySearchTree<T, N>::rotate_right(N<T> * ch, N<T> * par, N<T> * grand) {
    if(grand == nullptr) {
        this->root = par->left;
    }
    else {
        if(grand->left == par) {
            grand->left = ch;
        }
        else if(grand->right == par) {
            grand->right = ch;
        }
    }

    par->left = ch->right;
    ch->right = par;
    return;
}

template <class T, template <class> class N>
void BinarySearchTree<T, N>::rotate_left(N<T> * ch, N<T> * par, N<T> * grand) {
    if(grand == nullptr) {
        this->root = par->right;
    }
    else {
        if(grand->left == par) {
            grand->left = ch;
        }
        else if(grand->right == par) {
            grand->right = ch;
        }
    }

    par->right = ch->left;
    ch->left = par;
    return;
}

template <class T, template <class> class N>
void BinarySearchTree<T, N>::Balance(void) {
    this->balance(this->root);
    return;
}

#endif /* BINARYSEARCHTREE_HPP */
