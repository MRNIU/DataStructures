//
//  LinkedList.h
//  DS
//
//  Created by Zone.Niuzh on 2018/9/25.
//  Copyright © 2018 MRNIU. All rights reserved.
//
// 双向链表的实现

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "iostream"

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
    this->data = data;
    next = nullptr;
    prev = nullptr;
    return;
}

template <class T>
LLNode<T>::LLNode(){
    data = nullptr;
    next = nullptr;
    prev = nullptr;
    return;
}

template <class T>
class LinkedList {
private:
    LLNode<T> * head;
    LLNode<T> * tail;
public:
    LinkedList(void);
    LinkedList(const T data);
    // 添加到头部
    void AddtoHead(const T data);
    // 添加到尾部
    void AddtoTail(const T data);
    // 从头部删除
    T RemoveFromHead(void);
    // 从尾部删除
    T RemoveFromTail(void);
    // 获取头部数据
    T GetHead(void) const;
    // 获取尾部数据
    T GetTail(void) const;
    // 判断 key 是否在链表内
    bool Search(const T key) const;
    // 判断链表是否为空
    bool Empty(void) const;
    // 返回链表大小
    int size(void) const;
    // 输出元素
    void Display(void) const;
    // 排序
    void Sort(void);
    // 将链表转换为数组，返回原素数量
    size_t to_Array(T arr[]);
    // 将链表转换为 vector，返回 vector 大小
    size_t to_Vector(std::vector<T> &vect);
    ~LinkedList(void);
};

template <class T>
LinkedList<T>::LinkedList(){
    head=tail= nullptr;
    return;
}

template <class T>
LinkedList<T>::LinkedList(const T data){
    head=tail=new LLNode<T>(data);
    return;
}

template <class T>
void LinkedList<T>::AddtoHead(const T data){
    // 如果链表为空
    if(Empty()){
        // 则使头尾指针均指向 new 的节点
        head=tail=new LLNode<T>(data);
    }
    // 否则将头指针换成 new 的节点
    else{
        head->prev=new LLNode<T>(data);
        head->prev->next=head;
        head=head->prev;
    }
    return;
}

template <class T>
void LinkedList<T>::AddtoTail(const T data){
    // 如果链表为空
    if(Empty()){
        // 则使头尾指针均指向 new 的节点
        head=tail=new LLNode<T>(data);
    } else{
        tail->next=new LLNode<T>(data);
        tail->next->prev=tail;
        tail=tail->next;
    }
    return;
}

template <class T>
T LinkedList<T>::RemoveFromHead(void){
    // 如果链表为空
    if(Empty()){
        throw ("Linked List is empty!");
    }
    // 仅有一个元素
    else if ((head == tail)&&(head != nullptr)){
        T tmp = head->data;
        head = tail = nullptr;
        return tmp;
    } else{
        head = head->next;
        T tmp = head->prev->data;
        head->prev = nullptr;
        return tmp;
    }
}

template <class T>
T LinkedList<T>::RemoveFromTail(void){
    // 如果链表为空
    if(Empty()){
        return  nullptr;
    }
    // 仅有一个元素
    else if ((head == tail)&&(tail != nullptr)){
        T tmp = tail->data;
        head=tail = nullptr;
        return tmp;
    } else{
        tail = tail->prev;
        T tmp = tail->next->data;
        tail->next = nullptr;
        return tmp;
    }
}

template <class T>
T LinkedList<T>::GetHead() const{
    if(Empty())
        return 0;
    else
        return head->data;
}

template <class T>
T LinkedList<T>::GetTail() const{
    if(Empty())
        return 0;
    else
        return tail->data;
}


template <class T>
bool LinkedList<T>::Search(const T key) const{
    LLNode<T> * tmp=head;
    while (tmp->next != nullptr) {
        if(tmp->data == key)
            return true;
        tmp = tmp->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::Empty(void) const{
    // 如果头指针为空，则链表为空
    return head== nullptr;
}

template <class T>
int LinkedList<T>::size() const{
    if(head==nullptr){
        return 0;
    }
    else{
        int count=  1;
        LLNode<T> * tmp = head;
        while(tmp->next != nullptr){
            count += 1;
            tmp = tmp->next;
        }
        return count;
    }
}

template <class T>
void LinkedList<T>::Display(void) const{
    auto tmp = head;
    while(tmp!=nullptr){
        std::cout<<tmp->data<<std::endl;
        tmp = tmp->next;
    }
    return;
}

// 获取链表的第 x 个元素
template <typename T>
static LLNode<T> * get_nth_entry(LLNode<T> * head, size_t n){
    auto entry = head;
    for (auto i=0; i<n; i++) {
        if (entry == nullptr) {
            return nullptr;
        }
        entry = entry->next;
    }
    return entry;
}

#define GET_DATA(head, n) (get_nth_entry(head, n)->data)

// 插入排序
template <typename T>
static void sort(LLNode<T> *node, size_t n) {
    for(auto j=0; j< n; j++){
        T key= GET_DATA(node,j);
        auto i=j-1;
        while(i>=0 && GET_DATA(node,i)>key){
            GET_DATA(node, i+1) = GET_DATA(node, i);
            i--;
        }
        GET_DATA(node, i+1)=key;
    }
    return;
}

template <class T>
void LinkedList<T>::Sort(void){
    sort(head, size());
    return;
}

template <class T>
LinkedList<T>::~LinkedList(void){
    while(!Empty()){
        LLNode<T> * tmp = head->next;
        head = nullptr;
        head = tmp;
    }
    return;
}

#endif /* LINKEDLIST_HPP */
