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
#include "RedBlackTree.hpp"
#include "SortAlgorithm.hpp"

using namespace std;

clock_t startTime=clock(),
        endTime;
int main(int argc, const char * argv[]) {
    AVLTree<AVLN, int> avl(15);
    avl.Insert(10);
    avl.Insert(20);
    avl.Insert(5);
    
    avl.Delete(20);
    
    avl.DisplayTree();
    return 0;
}

