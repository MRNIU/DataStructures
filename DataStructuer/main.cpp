//
//  main.cpp
//  DS
//
//  Created by Zone.Niuzh on 2018/9/25.
//  Copyright © 2018 MRNIU. All rights reserved.
//

#include <iostream>
#include "time.h"
#include "Stack.hpp"
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "BinarySearchTree.hpp"
#include "AVLTree.hpp"
#include "SplayingTree.hpp"
#include "Heap.hpp"
#include "RedBlackTree.hpp"
#include "SortAlgorithm.hpp"

using namespace std;

clock_t startTime = clock(),
        endTime = 0;

int main(int argc, const char * argv[]) {
    Heap<int> heap;
    heap.Push(2);
    heap.Push(8);
    heap.Push(6);
    heap.Push(1);
    heap.Push(10);
    heap.Push(15);
    heap.Push(3);
    heap.Push(12);
    heap.Push(11);
    heap.Display();
    return 0;
}

