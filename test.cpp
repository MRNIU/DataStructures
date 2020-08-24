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

#include "iostream"
#include "vector"
#include "assert.h"

bool test_LinkedList(void) {
    LinkedList<int> LL(233);
    LL.AddtoHead(0);
    LL.AddtoHead(1);
    LL.AddtoHead(4);
    LL.AddtoHead(2);
    LL.Sort();
//    LL.Display();
    
    int a[10] = { 0 };
    auto n = LL.to_Array(a);
    assert(n == 5);
    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 2);
    assert(a[3] == 4);
    assert(a[4] == 233);
    assert(a[5] == 0);
    
    std::vector<int> v(0);
    size_t m = LL.to_Vector(v);
    assert(m == 5);
    assert(v[0] == 0);
    assert(v[1] == 1);
    assert(v[2] == 2);
    assert(v[3] == 4);
    assert(v[4] == 233);
    return true;
}

bool test_Queue(void) {
    Queue<int> queue(233);
    queue.EnQueue(0);
    queue.EnQueue(1);
    queue.EnQueue(4);
    queue.EnQueue(2);
    
    int a[10] = { 0 };
    auto n = queue.to_Array(a);
    assert(n == 5);
    assert(a[0] == 233);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 4);
    assert(a[4] == 2);
    assert(a[5] == 0);
    
    std::vector<int> v(0);
    size_t m = queue.to_Vector(v);
    assert(m == 5);
    assert(v[0] == 233);
    assert(v[1] == 0);
    assert(v[2] == 1);
    assert(v[3] == 4);
    assert(v[4] == 2);
    
    queue.DeQueue();
    int i = queue.GetFirst();
    assert(i == 0);
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
