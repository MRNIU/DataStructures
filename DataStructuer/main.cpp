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
    //cout<<bt.Search(233)<<endl;
    
    int a[]={5,4,3,2,1,0,-1,-11,-2};
    sort_bubble233(begin(a), end(a));
    //for(auto i=0;i<sizeof(a)/sizeof(*a);i++)
    for(auto i:a)
        cout<<i<<endl;
    
    cout << "Hello, World!\n" << endl;
    
    return 0;
}

