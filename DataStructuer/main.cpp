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
#include "RedBlackTree.hpp"
#include "SortAlgorithm.hpp"

using namespace std;

clock_t startTime=clock(),
        endTime;
int main(int argc, const char * argv[]) {
    AVLTree<int> avl(25);
    avl.Insert(15);
    avl.Insert(30);
    avl.Insert(5);
    avl.Insert(20);
    avl.Insert(35);
    avl.Insert(18);
    
    avl.Delete(35);
    
    avl.DisplayTree();
    return 0;
}

