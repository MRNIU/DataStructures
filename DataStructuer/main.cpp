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
#include "SortAlgorithm.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    BinarySearchTree<int> bt;
    BinarySearchTree<int> bt2(233);
    cout<<"search 233 "<<bt2.Search(233)<<endl;
    bt2.Insert(66666);
//    bt2.Insert(66666);
//    bt2.Insert(77777);
    bt2.Insert(77777);
    bt2.Insert(5);
    bt2.Insert(3);
    bt2.Insert(7);
    bt2.Insert(1);
    bt2.Insert(2);
    bt2.Insert(4);
    bt2.Insert(6);
    bt2.Insert(8);
    cout<<"search 66666 "<<bt2.Search(66666)<<endl;
    cout<<"search 77777 "<<bt2.Search(77777)<<endl;
    cout<<"GETHEIGHT: "<<bt2.GetHeight()<<endl;
    cout<<"GETLEAF: "<<bt2.GetLeaf()<<endl;;

    
    
    
    cout << "Hello, World!\n" << endl;
    
    return 0;
}

