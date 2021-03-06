//
//  SplayingTree.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef SPLAYINGTREE_HPP
#define SPLAYINGTREE_HPP

#include "BinarySearchTree.hpp"
#include "AVLTree.hpp"

template <class T>
class SPYN {
public:
    T data;
    SPYN<T> * parent;
    SPYN<T> * left;
    SPYN<T> * right;
    SPYN(void);
    SPYN(T data, SPYN<T> * left = nullptr, SPYN<T> * right = nullptr);
    ~SPYN(void);
};

template <class T>
SPYN<T>::SPYN() {
    this->data = 0;
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
    return;
}

template <class T>
SPYN<T>::SPYN(T data, SPYN<T> * left, SPYN<T> * right) {
    this->data = data;
    this->parent = nullptr;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
SPYN<T>::~SPYN() {
    return;
}

template <class T>
class SPYTree : public BinarySearchTree<T, SPYN> {
protected:
    const bool insert(SPYN<T> * spyn, const T data) override final;
    const bool search_and_splay(SPYN<T> * spyn, const T data);

    const bool splaying(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand);
    void rotate_right(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand) override final; // 右旋 ok
    void rotate_left(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand) override final; // 左旋 ok

    void display_tree(SPYN<T> * bstn) const override final; // 打印树结构 ok

public:
    SPYTree(void);
    SPYTree(const T data);
    SPYTree(const T * arr, const size_t begin, const size_t end);
    ~SPYTree(void);


    const bool Insert(const T data) override final;  // 插入
    const bool Delete(const T data) override final; // 删除
    const bool Search_Splay(const T data);  // 带有 splay 算法的搜索操作
};

template <class T>
SPYTree<T>::SPYTree(void) : BinarySearchTree<T, SPYN>::BinarySearchTree() {
    return;
}

template <class T>
SPYTree<T>::SPYTree(const T data) : BinarySearchTree<T, SPYN>::BinarySearchTree(data) {
    return;
}

template <class T>
SPYTree<T>::SPYTree(const T * arr, const size_t begin, const size_t end) : BinarySearchTree<T, SPYN>::BinarySearchTree(arr, begin, end) {
    return;
}

template <class T>
SPYTree<T>::~SPYTree(void) {
    return;
}

template <class T>
const bool SPYTree<T>::splaying(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand) {
    if(ch == nullptr || par == nullptr) {
        return false;
    }

    while(ch != this->root) {
        if(par == this->root) {
            // 单一 splaying，ch 围绕 par 右旋
            if(par->left == ch) {
                this->rotate_right(ch, par, grand);
            }
            // 镜像情况
            else if(par->right == ch) {
                this->rotate_left(ch, par, grand);
            }
        }
        // ch 与其祖先同构
        else if(grand->left == par && par->left == ch) {
            // 同构 splaying，par 围绕 grand 右旋，ch 围绕 par 右旋
            this->rotate_right(par, grand, grand->parent);
            this->rotate_right(ch, par, par->parent);
        }
        // ch 与其祖先异构
        else if(grand->left == par && par->right == ch) {
            // 异构 splaying，ch 围绕 par 左旋，ch 围绕 grand 右旋
            this->rotate_left(ch, par, grand);
            this->display_tree(this->root);
            this->rotate_right(ch, grand, grand->parent);
            this->display_tree(this->root);
        }
        // 镜像情况
        else if(grand->right == par && par->right == ch) {
            this->rotate_left(par, grand, grand->parent);
            this->rotate_left(ch, par, par->parent);
        }
        else if(grand->right == par && par->left == ch) {
            this->rotate_right(ch, par, grand);
            this->rotate_left(ch, grand, grand->parent);
        }

        if(ch == this->root) {
            par =  nullptr;
            grand = nullptr;
        }
        else {
            par = ch->parent;
            grand = par->parent;
        }
    }
    return true;
}

template <class T>
const bool SPYTree<T>::insert(SPYN<T> * spyn, const T data) {
    std::cout << "insert: " << data << std::endl;

    if(this->search(spyn, data) )
        return false;

    // 树为空的情况
    if(spyn == nullptr) {
        spyn = new SPYN<T>(data);
        spyn->data = data;
        spyn->parent = nullptr;
        if(this->root == nullptr) {
            this->root = spyn;
        }
        return true;
    }
    else {
        SPYN<T> * par = nullptr,
            * ch = spyn;

        while(ch != nullptr) {
            par = ch;
            if(data < ch->data) {
                ch = ch->left;
            }
            else if(data > ch->data) {
                ch = ch->right;
            }
            else {
                return false;
            }
        }

        if(data < par->data) {
            par->left = new SPYN<T>(data);
            ch = par->left;
            ch->parent = par;
        }
        else if(data > par->data) {
            par->right = new SPYN<T>(data);
            ch = par->right;
            ch->parent = par;
        }
        else {
            return false;
        }
        return true;
    }
}

template <class T>
void SPYTree<T>::rotate_left(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand) {
    if(grand == nullptr) {
        this->root = par->right;
        par->right->parent = nullptr;
    }
    else {
        if(grand->left == par) {
            grand->left = ch;
        }
        else if(grand->right == par) {
            grand->right = ch;
        }
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
void SPYTree<T>::rotate_right(SPYN<T> * ch, SPYN<T> * par, SPYN<T> * grand) {
    if(grand == nullptr) {
        this->root = par->left;
        par->left->parent = nullptr;
    }
    else {
        if(grand->left == par) {
            grand->left = ch;
        }
        else if(grand->right == par) {
            grand->right = ch;
        }
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

// 搜索并做展开操作
template <class T>
const bool SPYTree<T>::search_and_splay(SPYN<T> * spyn, const T data) {
    if(spyn == nullptr) {
        return false;
    }
    if(data < spyn->data) {
        return search_and_splay(spyn->left, data);
    }
    else if(data > spyn->data) {
        return search_and_splay(spyn->right, data);
    }
    else {
        if(spyn != this->root) {
            this->splaying(spyn, spyn->parent, spyn->parent->parent);
        }
        return true;
    }
}

template <class T>
void SPYTree<T>::display_tree(SPYN<T> * spyn) const {
    std::cout << "display_tree" << std::endl;

    if(this->root != nullptr)
        std::cout << "root: " << this->root->data << std::endl;

    std::cout << std::endl;

    std::cout << "lvr" << std::endl;
    this->dfs_lvr(spyn, [&](SPYN<T> * spyn) {
        std::cout << spyn->data << std::endl;
    });

    std::cout << std::endl;

    std::cout << "lrv" << std::endl;
    this->dfs_lrv(spyn, [&](SPYN<T> * spyn) {
        std::cout << spyn->data << std::endl;
    });

    std::cout << std::endl;

    std::cout << "bfs" << std::endl;
    this->bfs(spyn, [&](SPYN<T> * spyn) {
        if(spyn == this->root) {
            std::cout << spyn->data << " parent: nullptr" << std::endl;
        } else {
            std::cout << spyn->data << " parent: " << spyn->parent->data << std::endl;
        }
    });

    std::cout << std::endl;
    return;
}

template <class T>
const bool SPYTree<T>::Insert(const T data) {
    this->insert(this->root, data);
    return true;
}

template <class T>
const bool SPYTree<T>::Delete(const T data) {

    return true;
}

template <class T>
const bool SPYTree<T>::Search_Splay(const T data) {
    return this->search_and_splay(this->root, data);
}

#endif /* SPLAYINGTREE_HPP */
