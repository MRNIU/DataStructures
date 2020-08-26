//
//  test_LinkedList.cpp
//  test
//
//  Created by NZH on 2020/8/24.
//  Copyright © 2020 Zone.N. All rights reserved.
//

#include "LinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "BinarySearchTree.hpp"
#include "AVLTree.hpp"
#include "B+Tree.hpp"
#include "BTree.hpp"
#include "Heap.hpp"
#include "KDTree.hpp"
#include "RedBlackTree.hpp"
#include "TreapTree.hpp"
#include "SplayingTree.hpp"

#include "test.h"

#include "iostream"
#include "vector"
#include "assert.h"

bool Test::TestLinkedList(void) {
    LinkedList<int> LL(233);
    LL.AddtoHead(0);
    LL.AddtoHead(1);
    LL.AddtoHead(4);
    LL.AddtoHead(2);
    LL.Sort();

    int a[10] = { 0 };
    auto n = LL.ToArray(a);
    assert(n == 5);
    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 2);
    assert(a[3] == 4);
    assert(a[4] == 233);
    assert(a[5] == 0);

    std::vector<int> v(0);
    n = LL.ToVector(v);
    assert(n == 5);
    assert(v.at(0) == 0);
    assert(v.at(1) == 1);
    assert(v.at(2) == 2);
    assert(v.at(3) == 4);
    assert(v.at(4) == 233);

    LL.AddtoTail(666);
    v.clear();
    n = LL.ToVector(v);
    assert(n == 6);
    assert(v.at(5) == 666);

    assert(LL.RemoveFromHead() == 0);
    assert(LL.RemoveFromTail() == 666);
    assert(LL.RemoveFromTail() == 233);
    assert(LL.RemoveFromTail() == 4);
    assert(LL.RemoveFromTail() == 2);
    assert(LL.RemoveFromTail() == 1);
    assert(LL.RemoveFromTail() == 0);
    assert(LL.Empty() == true);

    LL.AddtoHead(233);
    LL.AddtoHead(0);
    LL.AddtoHead(4);
    LL.AddtoHead(1);
    LL.AddtoHead(2);
    v.clear();
    n = LL.ToVector(v);
    assert(n == 5);
    assert(LL.Size() == 5);
    assert(v.at(4) == 233);
    assert(v.at(3) == 0);
    assert(v.at(2) == 4);
    assert(v.at(1) == 1);
    assert(v.at(0) == 2);

    assert(LL.Search(0) == true);
    assert(LL.Search(1) == true);
    assert(LL.Search(2) == true);
    assert(LL.Search(4) == true);
    assert(LL.Search(233) == true);

    return true;
}

bool Test::TestQueue(void) {
    Queue<int> queue(233);
    queue.EnQueue(0);
    queue.EnQueue(1);
    queue.EnQueue(4);
    queue.EnQueue(2);

    int a[10] = { 0 };
    auto n = queue.ToArray(a);
    assert(n == 5);
    assert(a[0] == 233);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 4);
    assert(a[4] == 2);
    assert(a[5] == 0);

    std::vector<int> v(0);
    size_t m = queue.ToVector(v);
    assert(m == 5);
    assert(v.at(0) == 233);
    assert(v.at(1) == 0);
    assert(v.at(2) == 1);
    assert(v.at(3) == 4);
    assert(v.at(4) == 2);

    queue.DeQueue();
    int i = queue.GetFirst();
    assert(i == 0);
    
    return true;
}

bool Test::TestStack(void) {
    Stack<int> stack(233);
    stack.Push(0);
    stack.Push(1);
    stack.Push(4);
    stack.Push(2);
    
    int a[10] = { 0 };
    auto n = stack.ToArray(a);
    assert(n == 5);
    assert(a[0] == 2);
    assert(a[1] == 4);
    assert(a[2] == 1);
    assert(a[3] == 0);
    assert(a[4] == 233);
    assert(a[5] == 0);

    std::vector<int> v(0);
    size_t m = stack.ToVector(v);
    assert(m == 5);
    assert(v.at(0) == 2);
    assert(v.at(1) == 4);
    assert(v.at(2) == 1);
    assert(v.at(3) == 0);
    assert(v.at(4) == 233);

    stack.Pop();
    int i = stack.Top();
    assert(i == 4);
    
    return true;
}

bool Test::TestBinarySearchTree(void) {
    BinarySearchTree<int> bst(233);
    
    bst.Insert(0);
    bst.Insert(1);
    bst.Insert(4);
    bst.Insert(2);
    assert(bst.GetHeight() == 5);
    assert(bst.GetNodes() == 5);
    assert(bst.GetLeaf() == 1);
    
    int a[10] = { 0 };
    size_t n = bst.ToArrayLVR(a);
    assert(n == 5);
    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 2);
    assert(a[3] == 4);
    assert(a[4] == 233);
    assert(a[5] == 0);
    
    std::vector<int> v;
    size_t m = bst.ToVectorBFS(v);
    assert(m == 5);
    assert(v.at(0) == 233);
    assert(v.at(1) == 0);
    assert(v.at(2) == 1);
    assert(v.at(3) == 4);
    assert(v.at(4) == 2);
    
    bst.Balance();
    v.clear();
    bst.ToVectorBFS(v);
    assert(v.at(0) == 4);
    assert(v.at(1) == 1);
    assert(v.at(2) == 233);
    assert(v.at(3) == 0);
    assert(v.at(4) == 2);
    v.clear();
    bst.ToVectorLRV(v);
    assert(v.at(0) == 0);
    assert(v.at(1) == 2);
    assert(v.at(2) == 1);
    assert(v.at(3) == 233);
    assert(v.at(4) == 4);
    
    bst.Delete(4);
    bst.Display();
    
    return true;
}

bool Test::TestAVLTree(void) {
    return true;
}

bool Test::TestBPlusTree(void) {
    return true;
}

bool Test::TestHeap(void) {
    return true;
}

bool Test::TestKDTree(void) {
    return true;
}

bool Test::TestSplayingTree(void) {
    return true;
}

bool Test::TestTreapTree(void) {
    return true;
}
