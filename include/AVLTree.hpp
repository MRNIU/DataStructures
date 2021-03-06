//
//  AVLTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2019/2/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "BinarySearchTree.hpp"

#define BALANCE_FACTOR 2

template <class T>
class AVLN {
public:
    T data;
    int balance_factor;
    AVLN<T> * parent;
    AVLN<T> * left;
    AVLN<T> * right;
    AVLN(void);
    AVLN(T data, int factor = 0, AVLN<T> * left = nullptr, AVLN<T> * right = nullptr);
    ~AVLN(void);
};

template <class T>
AVLN<T>::AVLN() {
    this->data = 0;
    this->balance_factor = 0;
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
    return;
}

template <class T>
AVLN<T>::AVLN(T data, int factor, AVLN<T> * left, AVLN<T> * right) {
    this->data = data;
    this->balance_factor = factor;
    this->parent = nullptr;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
AVLN<T>::~AVLN() {
    delete left;
    delete right;
    delete parent;
    return;
}

template <class T>
class AVLTree : public BinarySearchTree<T, AVLN> {
protected:
    const bool insert(AVLN<T> * avln, const T data) override final;

    AVLN<T> * get_balance_node(AVLN<T> * ch);
    const bool update_balance_factor(AVLN<T> * avln);
    const bool update_balance_factor_bottom_up(AVLN<T> * avln);
    const bool balance_insert(AVLN<T> * bn);
    const bool balance_delete(AVLN<T> * bn);
    void rotate_right(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand) override final; // 右旋 ok
    void rotate_left(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand) override final; // 左旋 ok
    void rotate_lr(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand);
    void rotate_rl(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand);

    void display_tree(AVLN<T> * bstn) const override final; // 打印树结构 ok

public:
    AVLTree(void);
    AVLTree(const T data);
    AVLTree(const T * arr, const size_t begin, const size_t end);
    ~AVLTree(void);

    const bool Delete(const T data) override final; // 删除
};

template <class T>
AVLTree<T>::AVLTree(void) : BinarySearchTree<T, AVLN>::BinarySearchTree() {
    return;
}

template <class T>
AVLTree<T>::AVLTree(const T data) : BinarySearchTree<T, AVLN>::BinarySearchTree(data) {
    return;
}

template <class T>
AVLTree<T>::AVLTree(const T * arr, const size_t begin, const size_t end) : BinarySearchTree<T, AVLN>::BinarySearchTree(arr, begin, end) {
    return;
}

template <class T>
AVLTree<T>::~AVLTree(void) {
    //    this->clean(this->root);
    return;
}

template <class T>
const bool AVLTree<T>::insert(AVLN<T> * avln, const T data) {
    if(this->search(avln, data) )
        return false;

    // 树为空的情况
    if(avln == nullptr) {
        avln = new AVLN<T>(data);
        avln->data = data;
        avln->parent = nullptr;
        if(this->root == nullptr) {
            this->root = avln;
        }
        return true;
    }
    else {
        AVLN<T> * par = nullptr,
            * ch = avln,
            * bn = nullptr;

        while(ch != nullptr) {
            par = ch;
            if(data < ch->data)
                ch = ch->left;
            else if(data > ch->data)
                ch = ch->right;
            else
                return false;
        }

        if(data < par->data) {
            par->left = new AVLN<T>(data);
            ch = par->left;
            ch->parent = par;
            bn = this->get_balance_node(ch);
            if(bn != nullptr) {
                this->balance_insert(bn);
            }
        }
        else {
            par->right = new AVLN<T>(data);
            ch = par->right;
            ch->parent = par;
            bn = this->get_balance_node(ch);
            if(bn != nullptr) {
                this->balance_insert(bn);
            }
        }
        return true;
    }
    return true;
}

template <class T>
const bool AVLTree<T>::Delete(const T data) {
    AVLN<T> * par = this->get_node_prev(this->root, data),
        * tmp = nullptr;

    this->find_and_del_by_copy(data);
    this->update_balance_factor(this->root);

    while(par != nullptr) {
        std::cout << "node: " << par->data << std::endl;
        tmp = this->get_balance_node(par);
        this->balance_delete(tmp);
        par = par->parent;
    }
    return true;
}

// 更新所有节点的平衡因子信息
template <class T>
const bool AVLTree<T>::update_balance_factor(AVLN<T> * avln) {
    this->bfs(avln, [&](AVLN<T> * avln) {
        avln->balance_factor = this->get_height(avln->right) - this->get_height(avln->left);
    });

    return true;
}

// 更新节点平衡信息，自底向上计算方法，需要节点中包含其父节点的信息
// 在插入节点时使用
// avln 为刚插入的节点
template <class T>
const bool AVLTree<T>::update_balance_factor_bottom_up(AVLN<T> * avln) {
    AVLN<T> * par = avln->parent;
    if(avln == par->left) {
        par->balance_factor--;
    }
    else if(avln == par->right) {
        par->balance_factor++;
    }

    while(par != this->root && par->balance_factor != BALANCE_FACTOR && par->balance_factor != -BALANCE_FACTOR) {
        avln = avln->parent;
        par = par->parent;

        if(avln->balance_factor == 0) {
            return true;
        }

        if(avln == par->left) {
            par->balance_factor--;
        } else {
            par->balance_factor++;
        }
    }
    return true;
}

template <class T>
AVLN<T> * AVLTree<T>::get_balance_node(AVLN<T> * avln) {
    if(avln == this->root) {
        return nullptr;
    }

    AVLN<T> * par = avln->parent;
    if(par->balance_factor == BALANCE_FACTOR || par->balance_factor == -BALANCE_FACTOR) {
        return par;
    }

    return nullptr;
}

template <class T>
const bool AVLTree<T>::balance_insert(AVLN<T> * bn) {
    if(bn->balance_factor == BALANCE_FACTOR) {
        // 插入的节点在右子树的右子树上
        if(bn->right->balance_factor == BALANCE_FACTOR - 1) {
            std::cout << "l: " << bn->data << std::endl;
            this->rotate_left(bn->right, bn, bn->parent);
        }
        // 在右子树的左子树插入
        else {
            std::cout << "rl: " << bn->data << std::endl;
            this->rotate_rl(bn->right->left, bn->right, bn);
        }
    }
    // 对称情况，插入的节点在左子树的左子树上
    else if(bn->balance_factor == -BALANCE_FACTOR) {
        if(bn->left->balance_factor == -(BALANCE_FACTOR - 1) ) {
            std::cout << "r: " << bn->data << std::endl;
            this->rotate_right(bn->left, bn, bn->parent);
        }
        // 对称情况，在左子树的右子树插入
        else {
            std::cout << "lr: " << bn->data << std::endl;
            this->rotate_lr(bn->left->right, bn->left, bn);
        }
    }
    this->update_balance_factor(this->root);
    return true;
}

template <class T>
const bool AVLTree<T>::balance_delete(AVLN<T> * bn) {
    if(bn == nullptr) {
        bn = this->root;
    }

    std::cout << "bn: " << bn->balance_factor << std::endl;
    if(bn->balance_factor == BALANCE_FACTOR) {
        // 情况一，d 是被删除的节点，p 为 bn，围绕 p 左旋 q
        //         p
        //        / \
        //       d   q
        //            \
        //             n
        if(bn->right->balance_factor == BALANCE_FACTOR - 1) {
            std::cout << "1: " << bn->data << std::endl;
            this->rotate_left(bn->right, bn, bn->parent);
        }
        // 情况二，围绕 p 左旋 q
        //         p
        //        / \
        //       d   q
        //          / \
        //         n   n
        else if(bn->right->balance_factor == 0) {
            std::cout << "2: " << bn->data << std::endl;
            this->rotate_left(bn->right, bn, bn->parent);
        }
        // 情况三，围绕 q 右旋 r，围绕 p 左旋 r
        //         p
        //        / \
        //       n   q
        //      /   / \
        //     d   r   n
        //        /
        //       n
        else if(bn->right->balance_factor == -(BALANCE_FACTOR - 1) && bn->right->left->balance_factor == -(BALANCE_FACTOR - 1) ) {
            std::cout << "3: " << bn->data << std::endl;
            this->rotate_rl(bn->right->left, bn->right, bn);
        }
        // 情况四，围绕 q 右旋 r，围绕 p 左旋 r
        //         p
        //        / \
        //       n   q
        //      /   / \
        //     d   r   n
        //          \
        //           n
        else if(bn->right->balance_factor == -(BALANCE_FACTOR - 1) && bn->right->left->balance_factor == BALANCE_FACTOR - 1) {
            std::cout << "4: " << bn->data << std::endl;
            this->rotate_rl(bn->right->left, bn->right, bn);
        }
    }
    // 对称情况
    else if(bn->balance_factor == -BALANCE_FACTOR) {
        // 情况五，d 是被删除的节点，p 为 bn，围绕 p 右旋 q
        //         p
        //        / \
        //       q   d
        //      /
        //     n
        if(bn->left->balance_factor == -(BALANCE_FACTOR - 1) ) {
            std::cout << "5: " << bn->data << std::endl;
            this->rotate_right(bn->left, bn, bn->parent);
        }
        // 情况六，围绕 p 右旋 q
        //         p
        //        / \
        //       q   d
        //      / \
        //     n   n
        else if(bn->left->balance_factor == 0) {
            std::cout << "6: " << bn->data << std::endl;
            this->rotate_right(bn->left, bn, bn->parent);
        }
        // 情况七，围绕 q 左旋 r，围绕 p 右旋 r
        //         p
        //        / \
        //       q   n
        //      / \   \
        //     n   r   d
        //          \
        //           n
        else if(bn->left->balance_factor == (BALANCE_FACTOR - 1) && bn->left->right->balance_factor == BALANCE_FACTOR - 1) {
            std::cout << "7: " << bn->data << std::endl;
            std::cout << "7: " << bn->left->balance_factor << std::endl;
            std::cout << "7: " << bn->left->right->balance_factor << std::endl;
            this->rotate_lr(bn->left->right, bn->left, bn);
        }
        // 情况八，围绕 q 左旋 r，围绕 p 右旋 r
        //         p
        //        / \
        //       q   n
        //      / \   \
        //     n   r   d
        //        /
        //       n
        else if(bn->left->balance_factor == (BALANCE_FACTOR - 1) && bn->left->right->balance_factor == -(BALANCE_FACTOR - 1) ) {
            std::cout << "8: " << bn->data << std::endl;
            this->rotate_lr(bn->left->right, bn->left, bn);
        }
        else {
            std::cout << "000000: " << bn->data << std::endl;
        }
    }
    this->update_balance_factor(this->root);
    return true;
}

template <class T>
void AVLTree<T>::rotate_left(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand) {
    if(grand == nullptr) {
        this->root = par->right;
        par->right->parent = nullptr;
    }
    if(grand != nullptr) {
        grand->left = ch;
        ch->parent = grand;
    }

    par->right = ch->left;
    if(ch->left != nullptr) {
        ch->left->parent = par;
    }
    ch->left = par;
    par->parent = ch;
    return;
}

template <class T>
void AVLTree<T>::rotate_right(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand) {
    if(grand == nullptr) {
        this->root = par->left;
        par->left->parent = nullptr;
    }
    if(grand != nullptr) {
        grand->right = ch;
        ch->parent = grand;
    }

    par->left = ch->right;
    if(ch->right != nullptr) {
        ch->right->parent = par;
    }
    ch->right = par;
    par->parent = ch;
    return;
}


template <class T>
void AVLTree<T>::rotate_lr(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand) {
    this->rotate_left(ch, par, grand);
    this->rotate_right(ch, grand, grand->parent);
    return;
}

template <class T>
void AVLTree<T>::rotate_rl(AVLN<T> * ch, AVLN<T> * par, AVLN<T> * grand) {
    this->rotate_right(ch, par, grand);
    this->rotate_left(ch, grand, grand->parent);
    return;
}

template <class T>
void AVLTree<T>::display_tree(AVLN<T> * avln) const {
    std::cout << "display_tree" << std::endl;

    if(this->root != nullptr)
        std::cout << "root: " << this->root->data << std::endl;

    std::cout << std::endl;

    std::cout << "lvr" << std::endl;
    this->dfs_lvr(avln, [&](AVLN<T> * avln) {
        std::cout << avln->data << " factor: " << avln->balance_factor << std::endl;
    });

    std::cout << std::endl;

    std::cout << "lrv" << std::endl;
    this->dfs_lrv(avln, [&](AVLN<T> * avln) {
        std::cout << avln->data << " factor: " << avln->balance_factor << std::endl;
    });

    std::cout << std::endl;

    std::cout << "bfs" << std::endl;
    this->bfs(avln, [&](AVLN<T> * avln) {
        std::cout << avln->data << " factor: " << avln->balance_factor << std::endl;
    });

    std::cout << std::endl;
    return;
}

#endif /* AVLTREE_HPP */
