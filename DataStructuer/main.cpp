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
    Heap<int> heap1;
    heap1.Push(2);
    heap1.Push(8);
    heap1.Push(6);
    heap1.Push(1);
    heap1.Push(10);
    heap1.Push(15);
    heap1.Push(3);
    heap1.Push(12);
    heap1.Push(11);
    heap1.Display();
    return 0;
}

