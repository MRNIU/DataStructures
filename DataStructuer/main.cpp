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
//    AVLTree<int> bt3(233);
////    BinarySearchTree<int> bt3(233);
//    cout<<"search 233 "<<bt3.Search(233)<<endl;
//    bt3.Insert(66666);
////    bt3.Insert(66666);
////    bt3.Insert(77777);
//    bt3.Insert(77777);
//    bt3.Insert(5);
//    bt3.Insert(3);
//    bt3.Insert(7);
//    bt3.Insert(1);
//    bt3.Insert(2);
//    bt3.Insert(4);
//    bt3.Insert(6);
//    bt3.Insert(8);
//    bt3.Insert(9);
//    int tmp666=10000;
////    bt3.Insert(tmp666);
//    bt3.Insert(11);
//    bt3.Insert(10);
//    bt3.Insert(12);
//    cout<<"search 66666 "<<bt3.Search(66666)<<endl;
//    cout<<"search 77777 "<<bt3.Search(77777)<<endl;
//    cout<<"GETHEIGHT: "<<bt3.GetHeight()<<endl;
//    cout<<"GETLEAF: "<<bt3.GetLeaf()<<endl;
//    cout<<"GETNODES: "<<bt3.GetNodes()<<endl;
//    bt3.DisplayTree();
//    endTime = clock();
//    cout << "Totle Time : " <<(long double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
//    cout << "Hello, World!\n" << endl;
//    return 0;
    AVLTree<AVLN, int> avl(15);
    avl.Insert(10);
    avl.Insert(20);
    avl.Insert(5);
    avl.Insert(13);
    avl.Insert(12);
//    avl.Delete(12);
//    avl.Insert(1);
//    avl.Insert(17);
//    avl.Insert(25);
//    avl.Insert(30);
//    avl.Insert(40);
//
    
    avl.DisplayTree();
    return 0;
}

