//
//  main.cpp
//  DS
//
//  Created by Zone.Niuzh on 2018/9/25.
//  Copyright © 2018 MRNIU. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "BinarySearchTree.hpp"
#include "CompleteBinaryTree.hpp"
#include "SortAlgorithm.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    BinarySearchTree<int> bt3(233);
    cout<<"search 233 "<<bt3.Search(233)<<endl;
    bt3.Insert(66666);
//    bt3.Insert(66666);
//    bt3.Insert(77777);
    bt3.Insert(77777);
    bt3.Insert(5);
    bt3.Insert(3);
    bt3.Insert(7);
    bt3.Insert(1);
    bt3.Insert(2);
    bt3.Insert(4);
    bt3.Insert(6);
    bt3.Insert(8);
    bt3.Insert(9);
    bt3.Insert(11);
    bt3.Insert(10);
    bt3.Insert(12);
    cout<<"search 66666 "<<bt3.Search(66666)<<endl;
    cout<<"search 77777 "<<bt3.Search(77777)<<endl;
    cout<<"GETHEIGHT: "<<bt3.GetHeight()<<endl;
    cout<<"GETLEAF: "<<bt3.GetLeaf()<<endl;
    cout<<"GETNODES: "<<bt3.GetNodes()<<endl;
    bt3.DisplayTree();

    
    
    
    cout << "Hello, World!\n" << endl;
    
    return 0;
}

