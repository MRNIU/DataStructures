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

    if(spyt.Search_Splay(25))
        std::cout<<"ok1"<<std::endl;
//    spyt.DisplayTree();
//    if(spyt.Search_Splay(15))
        std::cout<<"ok2"<<std::endl;
//    spyt.DisplayTree();
    if(spyt.Search_Splay(20))
        std::cout<<"ok3"<<std::endl;
//    spyt.DisplayTree();
    if(spyt.Search_Splay(5))
        std::cout<<"ok4"<<std::endl;
//    spyt.DisplayTree();
    if(spyt.Search_Splay(45))
        std::cout<<"ok5"<<std::endl;
//    if(spyt.Search_Splay(25))
//        std::cout<<"ok6"<<std::endl;
    
//    spyt.Insert(18);
//    spyt.DisplayTree();
    
//    spyt.Delete(35);
    
    spyt.DisplayTree();
    return 0;
}

