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
//    SPYTree<int> spyt(25);
//    spyt.Insert(15);
//    spyt.Insert(20);
//    spyt.Insert(5);
//    spyt.Insert(35);
//    spyt.Insert(40);
//    spyt.Insert(45);
//    spyt.DisplayTree();
//
//
//    spyt.Search_Splay(25);
//    spyt.Search_Splay(15);
//    spyt.Search_Splay(20);
//    spyt.Search_Splay(5);
//    spyt.Search_Splay(45);
    

    SPYTree<int> spyt(50);
    spyt.Insert(40);
    spyt.Insert(60);
    spyt.Insert(30);
    spyt.Insert(55);
    spyt.Insert(70);
    spyt.Insert(20);
    spyt.DisplayTree();

    spyt.Search_Splay(50);
    spyt.Search_Splay(60);
    spyt.Search_Splay(55);
    spyt.Search_Splay(70);
    spyt.Search_Splay(20);

    spyt.DisplayTree();
    return 0;
}

