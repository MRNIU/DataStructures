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
#include "TreapTree.hpp"
#include "RedBlackTree.hpp"
#include "SortAlgorithm.hpp"

using namespace std;

clock_t startTime = clock(),
        endTime = 0;

int main(int argc, const char * argv[]) {
    TreapTree<int> trep1;
    trep1.Insert(50);
    trep1.Insert(40);
    trep1.Insert(60);
    trep1.Insert(30);
    trep1.Insert(55);
    trep1.Insert(70);
    trep1.Insert(20);
    
    trep1.Delete(55);
    
    trep1.DisplayTree();
    return 0;
}

