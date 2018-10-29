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

using namespace std;

int main(int argc, const char * argv[]) {
    BinarySearchTree<int> bt;
    BinarySearchTree<int> bt2(233);
    cout<<bt.Search(233)<<endl;;
    
    
    cout << "Hello, World!\n" << endl;
    
    return 0;
}

