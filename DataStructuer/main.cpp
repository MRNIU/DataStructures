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

clock_t startTime = clock(),
        endTime = 0;
int main(int argc, const char * argv[]) {
    SPYTree<int> spyt(25);
    spyt.Insert(15);
    spyt.Insert(20);
    spyt.Insert(5);
    spyt.Insert(35);
    spyt.Insert(40);
    spyt.Insert(45);
    spyt.DisplayTree();
    
    std::cout<<"search 25"<<std::endl;
    spyt.Search_Splay(25);
    spyt.DisplayTree();
    
    std::cout<<"search 15"<<std::endl;
    spyt.Search_Splay(15);
    spyt.DisplayTree();
    
    std::cout<<"search 20"<<std::endl;
    spyt.Search_Splay(20);
    spyt.DisplayTree();
    
    std::cout<<"search 5"<<std::endl;
    spyt.Search_Splay(5);
    spyt.DisplayTree();
    
    std::cout<<"search 45"<<std::endl;
    spyt.Search_Splay(45);
    
//    spyt.Insert(18);
//    spyt.DisplayTree();
    
//    spyt.Delete(35);
    
    spyt.DisplayTree();
    return 0;
}

