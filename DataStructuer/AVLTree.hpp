//
//  AVLTree.hpp
//  DataStructuer
//
//  Created by Zone.N on 2019/2/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

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
    AVLN(T data, int factor = 0, AVLN<T> * left = NULL, AVLN<T> * right = NULL);
    ~AVLN(void);
};

template <class T>
AVLN<T>::AVLN() {
    this->data = 0;
    this->balance_factor = 0;
    this->parent = NULL;
    this->right = NULL;
    this->left = NULL;
    return;
}

template <class T>
AVLN<T>::AVLN(T data, int factor, AVLN<T> * left, AVLN<T> * right) {
    this->data = data;
    this->balance_factor = factor;
    this->parent = NULL;
    this->left = left;
    this->right = right;
    return;
}

template <class T>
AVLN<T>::~AVLN(){
    return;
}

template <template<class> class N, class T>
class AVLTree: public BinarySearchTree<N, T> {
protected:
    const bool insert(N<T> * avln, const T data) override final;
    const bool clean(N<T> * avln) override final;
    N<T> * get_balance_node(N<T> * ch, N<T> * par, N<T> * grand);
    const bool update_balance_factor(N<T> * avln);
    const bool balance(N<T> * bn);
    void avl_rotate_lr(N<T> * ch, N<T> * par, N<T> * grand);
    void avl_rotate_rl(N<T> * ch, N<T> * par, N<T> * grand);
    void display_tree(N<T> * bstn) const override final; // 打印树结构 ok
    
public:
    AVLTree(void);
    AVLTree(const T data);
    AVLTree(const T * arr, const size_t begin, const size_t end);
    ~AVLTree(void);
    
    const bool Insert(const T data) override final;  // 插入
    const bool Delete(const T data) override final; // 删除
};

template <template<class> class N, class T>
AVLTree<N, T>::AVLTree(void): BinarySearchTree<N, T>::BinarySearchTree(){
    return;
}

template <template<class> class N, class T>
AVLTree<N, T>::AVLTree(const T data): BinarySearchTree<N, T>::BinarySearchTree(data){
    return;
}

template <template<class> class N, class T>
AVLTree<N, T>::AVLTree(const T * arr, const size_t begin, const size_t end): BinarySearchTree<N, T>::BinarySearchTree(arr, begin, end){
    return;
}

template <template<class> class N, class T>
AVLTree<N, T>::~AVLTree(void){
    this->clean(this->root);
    return;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::insert(N<T> * avln, const T data){
    if(this->search(avln, data))
        return false;
    
    // 树为空的情况
    if(avln == NULL) {
        avln = new N<T>(data);
        avln->data = data;
        avln->parent = NULL;
        if(this->root == NULL){
            this->root = avln;
        }
        return true;
    }
    else{
        N<T> * par = NULL,
             * ch = avln,
             * bn = NULL;
        
        while(ch != NULL){
            par = ch;
            if(data < ch->data)
                ch = ch->left;
            else if(data > ch->data)
                ch = ch->right;
            else
                return false;
        }
        
        if(data < par->data){
            par->left = new N<T>(data);
            ch = par->left;
            ch->parent = par;
            bn = this->get_balance_node(ch, par, par->parent);
            if(bn != NULL){
                this->balance(bn);
            }
        }
        else{
            par->right = new N<T>(data);
            ch = par->right;
            ch->parent = par;
            bn = this->get_balance_node(ch, par, par->parent);
            if(bn != NULL){
                this->balance(bn);
            }
        }
        return true;
    }
    return true;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::Insert(const T data){
    return this->insert(this->root, data);
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::clean(N<T> * avln){
    
    return true;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::Delete(const T data){
    return true;
}

// 更新所有节点的平衡因子信息
template <template<class> class N, class T>
const bool AVLTree<N, T>::update_balance_factor(N<T> * avln){
    this->bfs(avln, [&](N<T> * avln){
        avln->balance_factor = this->get_height(avln->right) - this->get_height(avln->left);
    });

    return true;
}

// 自底向上计算方法，需要节点中包含其父节点的信息
template <template<class> class N, class T>
N<T> * AVLTree<N, T>::get_balance_node(N<T> * ch, N<T> * par, N<T> * grand){
    if(ch == par->left){
        par->balance_factor--;
    }
    else if(ch == par->right){
        par->balance_factor++;
    }
    
    while(par != this->root && par->balance_factor != BALANCE_FACTOR && par->balance_factor != -BALANCE_FACTOR){
        ch = ch->parent;
        par = par->parent;
        
        if(ch->balance_factor == 0){
            return NULL;
        }
        
        if(ch == par->left){
            par->balance_factor--;
        } else{
            par->balance_factor++;
        }
    }
    
    if(par->balance_factor == BALANCE_FACTOR || par->balance_factor == -BALANCE_FACTOR){
        return par;
    }
    
    return NULL;
}

template <template<class> class N, class T>
const bool AVLTree<N, T>::balance(N<T> * bn){
    if(bn->balance_factor == BALANCE_FACTOR){
        // 插入的节点在右子树的右子树上
        if(bn->right->balance_factor == BALANCE_FACTOR - 1){
            std::cout<<"l: "<<bn->data<<std::endl;
            this->bsw_rotate_left(bn->right, bn, bn->parent);
        }
        // 在右子树的左子树插入
        else{
            std::cout<<"rl: "<<bn->data<<std::endl;
            this->avl_rotate_rl(bn->right->left, bn->right, bn);
        }
    }
    // 对称情况，插入的节点在左子树的左子树上
    else if(bn->balance_factor == -BALANCE_FACTOR){
        if(bn->left->balance_factor == -(BALANCE_FACTOR - 1)){
            std::cout<<"r: "<<bn->data<<std::endl;
            this->bsw_rotate_right(bn->left, bn, bn->parent);
        }
        // 对称情况，在左子树的右子树插入
        else{
            std::cout<<"lr: "<<bn->data<<std::endl;
            this->avl_rotate_lr(bn->left->right, bn->left, bn);
        }
    }
    this->update_balance_factor(this->root);
    return true;
}

template <template<class> class N, class T>
void AVLTree<N, T>::avl_rotate_lr(N<T> * ch, N<T> * par, N<T> * grand){
    this->bsw_rotate_left(ch, par, grand);
    this->bsw_rotate_right(ch, grand, grand->parent);
    return;
}

template <template<class> class N, class T>
void AVLTree<N, T>::avl_rotate_rl(N<T> * ch, N<T> * par, N<T> * grand){
    this->bsw_rotate_right(ch, par, grand);
    this->bsw_rotate_left(ch, grand, grand->parent);
    return;
}

template <template<class> class N, class T>
void AVLTree<N, T>::display_tree(N<T> * avln) const {
    std::cout<<"display_tree"<<std::endl;
    
    if(this->root != NULL)
        std::cout<<"root: "<<this->root->data<<std::endl;
    
    std::cout<<std::endl;
    
    std::cout<<"lvr"<<std::endl;
    this->dfs_lvr(avln, [&](N<T>* avln){
        std::cout<<avln->data<<" factor: "<<avln->balance_factor<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"lrv"<<std::endl;
    this->dfs_lrv(avln, [&](N<T> * avln){
        std::cout<<avln->data<<" factor: "<<avln->balance_factor<<std::endl;
    });
    
    std::cout<<std::endl;
    
    std::cout<<"bfs"<<std::endl;
    this->bfs(avln, [&](N<T> * avln){
        std::cout<<avln->data<<" factor: "<<avln->balance_factor<<std::endl;
    });
    
    std::cout<<std::endl;
    return;
}

#endif /* AVLTree_hpp */
