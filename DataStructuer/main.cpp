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

using namespace std;

int main(int argc, const char * argv[]) {
    LinkedList<int> LL(1);
    LL.AddtoHead(2);
    LL.AddtoHead(3);
    LL.AddtoHead(4);
    LL.AddtoTail(5);
    cout<<LL.Search(6)<<endl;
    
    cout << "Hello, World!\n" << endl;
    
    return 0;
}
