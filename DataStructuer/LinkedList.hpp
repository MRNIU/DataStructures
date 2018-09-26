//
//  LinkedList.h
//  DS
//
//  Created by Zone.Niuzh on 2018/9/25.
//  Copyright © 2018 MRNIU. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

template <class T>
class LLNode {
public:
    T data;
    LLNode * next;
    LLNode * prev;
    LLNode(T data);
    LLNode(void);
    ~LLNode();
};

template <class T>
LLNode<T>::LLNode(T data){
    this->data=data;
    next=NULL;
    prev=NULL;
}

template <class T>
LLNode<T>::LLNode(){
    data=NULL;
    next=NULL;
    prev=NULL;
}

template <class T>
class LinkedList {
private:
    LLNode<T> * head;
    LLNode<T> * tail;
public:
    void test(void);    // 测试函数
    LinkedList(void);
    LinkedList(T data);
    void AddtoHead(T data); // 添加到头部
    void AddtoTail(T data); // 添加到尾部
    T RemoveFromHead(void); // 从头部删除
    T RemoveFromTail(void); // 从尾部删除
    T GetHead(void);    // 获取头部数据
    T GetTail(void);    // 获取尾部数据
    bool Search(T key); // 判断 key 是否在链表内
    bool Empty(void);   // 判断链表是否为空
    int size(void); // 返回链表大小
    ~LinkedList(void);
};

template <class T>
LinkedList<T>::LinkedList(){
    head=tail=NULL;
}

template <class T>
LinkedList<T>::LinkedList(T data){
    head=tail=new LLNode<T>(data);
}

template <class T>
void LinkedList<T>::AddtoHead(T data){
    if(Empty()){    // 如果链表为空
        head=tail=new LLNode<T>(data);  // 则使头尾指针均指向 new 的节点
    } else{ // 否则将头指针换成 new 的节点
        head->prev=new LLNode<T>(data);
        head->prev->next=head;
        head=head->prev;
    }
    return;
}

template <class T>
void LinkedList<T>::AddtoTail(T data){
    if(Empty()){    // 如果链表为空
        head=tail=new LLNode<T>(data);  // 则使头尾指针均指向 new 的节点
    } else{
        tail->next=new LLNode<T>(data);
        tail->next->prev=tail;
        tail=tail->next;
    }
    return;
}

template <class T>
T LinkedList<T>::RemoveFromHead(void){
    if(Empty()){    // 如果链表为空
        throw ("Linked List is empty!");
    } else if ((head==tail)&&(head!=NULL)){ // 仅有一个元素
        T tmp=head->data;
        head=tail=NULL;
        return tmp;
    } else{
        head=head->next;
        T tmp=head->prev->data;
        head->prev=NULL;
        return tmp;
    }
}

template <class T>
T LinkedList<T>::RemoveFromTail(void){
    if(Empty()){    // 如果链表为空
        return 0xCDCD;
    } else if ((head==tail)&&(tail!=NULL)){ // 仅有一个元素
        T tmp=tail->data;
        head=tail=NULL;
        return tmp;
    } else{
        tail=tail->prev;
        T tmp=tail->next->data;
        tail->next=NULL;
        return tmp;
    }
}

template <class T>
T LinkedList<T>::GetHead(){
    if(Empty())
        return 0xCDCD;
    else
        return head->data;
}

template <class T>
T LinkedList<T>::GetTail(){
    if(Empty())
        return 0xCDCD;
    else
        return tail->data;
}


template <class T>
bool LinkedList<T>::Search(T key){
    LLNode<T> * tmp=head;
    while (tmp->next!=NULL) {
        if(tmp->data==key)
            return true;
        tmp=tmp->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::Empty(void){
    return head==NULL;  // 如果头指针为空，则链表为空
}

template <class T>
int LinkedList<T>::size(){
    int count=1;
    LLNode<T> * tmp=head;
    while(tmp->next!=NULL){
        count+=1;
        tmp=tmp->next;
    }
    return count;
}

template <class T>
LinkedList<T>::~LinkedList(void){
    while(!Empty()){
        LLNode<T> * tmp=head->next;
        head=NULL;
        head=tmp;
    }
}

#include "iostream"
using namespace std;
template <class T>
void LinkedList<T>::test(void){
    LLNode<T>*tmp=head;
    while(tmp!=NULL){
        cout<<tmp->data<<endl;
        tmp=tmp->next;
    }
}

#endif /* LinkedList_h */
