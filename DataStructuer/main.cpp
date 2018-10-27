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

using namespace std;

int main(int argc, const char * argv[]) {
    //LinkedList<int> LL(233);
    Stack<int> st(233);
    st.Push(1);
    st.Push(2);
    st.Pop();
    st.Push(3);
    cout<<"top item of stack is "<<st.Top()<<endl;
    cout<<"bottom item of stack is "<<st.Bottom()<<endl;
    st.test();
    cout<<"size of stack "<<st.Size()<<endl;
    

    cout << "Hello, World!\n" << endl;
    
    return 0;
}

