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
//#include "AVLTree.hpp"
//#include "SplayingTree.hpp"
//#include "Heap.hpp"
//#include "TreapTree.hpp"
//#include "RedBlackTree.hpp"
#include "SortAlgorithm.hpp"

// TODO:
// Use mode C++ features in project
// Improve existing code

using namespace std;

clock_t startTime = clock(),
        endTime = 0;

int main(int argc, const char * argv[]) {
    BinarySearchTree<int> bst1;
    bst1.Insert(50);
    bst1.Insert(40);
    bst1.Insert(60);
    bst1.Insert(30);
    bst1.Insert(55);
    bst1.Insert(70);
    bst1.Insert(20);
    
//    bst1.Delete(55);
//    bst1.Delete(40);
    
    bst1.DisplayTree();
    return 0;
}

