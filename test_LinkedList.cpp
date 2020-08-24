//
//  test_LinkedList.cpp
//  test
//
//  Created by NZH on 2020/8/24.
//  Copyright © 2020 Zone.N. All rights reserved.
//

#include "LinkedList.hpp"
#include "AVLTree.hpp"
#include "B+Tree.hpp"
#include "BinarySearchTree.hpp"
#include "BTree.hpp"
#include "Heap.hpp"
#include "KDTree.hpp"
#include "RedBlackTree.hpp"
#include "Queue.hpp"
#include "TreapTree.hpp"
#include "Stack.hpp"
#include "SplayingTree.hpp"



bool test_LinkedList(void) {
    LinkedList<int>LL(233);
    LL.AddtoHead(0);
    LL.AddtoHead(1);
    LL.AddtoHead(4);
    LL.AddtoHead(2);
    LL.Sort();
    LL.Display();
    return true;
}

bool test_Queue(void) {
    return true;
}

bool test_AVLTree(void) {
    return true;
}

bool test_BPlusTree(void) {
    return true;
}

bool test_Heap(void) {
    return true;
}

bool test_KDTree(void) {
    return true;
}

bool test_SplayingTree(void) {
    return true;
}

bool test_Stack(void) {
    return true;
}

bool test_TreapTree(void) {
    return true;
}
