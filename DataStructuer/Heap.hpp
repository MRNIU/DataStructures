//
//  Heap.hpp
//  DataStructuer
//
//  Created by NZH on 2019/9/11.
//  Copyright © 2019 Zone.N. All rights reserved.
//

#ifndef HEAP_HPP
#define HEAP_HPP

// Max Heap
template <class T>
class Heap {
private:
    T * ves = nullptr;
    size_t curr_size;
    size_t max_size = 101;
    virtual const bool push_max(const T data);
    virtual const bool push_min(const T data);
    virtual const T pop_max(void);
    virtual const T pop_min(void);
    virtual const T get_top(void);  // 获取堆顶元素
    virtual const bool swap(T * x, T * y);
public:
    Heap(void);
    Heap(T * arr, size_t size);
    ~Heap(void);
    virtual const bool Push(const T data);    // 插入元素
    virtual const T Pop(void);  // 弹出堆顶元素
    virtual const T GetTop(void);  // 获取堆顶元素
    virtual void Display(void) const;
};

template <class T>
Heap<T>::Heap(){
    this->ves = new T [this->max_size];
    std::memset(this->ves, 0, this->max_size);
    this->curr_size = 0;
    return;
}

template <class T>
Heap<T>::Heap(T * arr, size_t size){
    if(arr != nullptr && size > 0){
        this->ves = new T [2 * size + 1];
        this->curr_size = size;
        this->max_size = 2 * size + 1;
        std::memset(this->ves, 0, this->max_size);
        for(int i = 0; i < size; i++){
            this->push_max(arr[i]);
        }
        return;
    }
}

template <class T>
Heap<T>::~Heap(){
    delete [] this->ves;
    return;
}

template <class T>
const bool Heap<T>::swap(T * x, T * y){
    T z = *x;
    *x = *y;
    *y = z;
    return true;
}

template <class T>
const bool Heap<T>::push_max(const T data){
    // 分配新的存储空间
    if(this->curr_size == this->max_size) {
        this->max_size = 2 * (this->max_size-1) + 1;
        T * new_ves = new T [this->max_size];
        std::memset(new_ves, 0, this->max_size * sizeof(T));
        std::memcpy(new_ves, this->ves, (this->curr_size + 1) * sizeof(T));
        delete [] this->ves;
        this->ves = new_ves;
    }
    
    if(this->curr_size == 0) {
        this->ves[1] = data;
        this->curr_size = 1;
    }
    else {
        // 自底向上方法
        this->curr_size++;
        this->ves[this->curr_size] = data;
        int i = (int)this->curr_size;
        while(i > 1 && ves[i] > ves[i/2]) {
            this->swap(&this->ves[i], &this->ves[i/2]);
            i /= 2;
        }
    }
    
    return true;
}

template <class T>
const bool Heap<T>::push_min(const T data){
    // 分配新的存储空间
    if(this->curr_size == this->max_size) {
        this->max_size = 2 * (this->max_size-1) + 1;
        T * new_ves = new T [this->max_size];
        std::memset(new_ves, 0, this->max_size * sizeof(T));
        std::memcpy(new_ves, this->ves, (this->curr_size + 1) * sizeof(T));
        delete [] this->ves;
        this->ves = new_ves;
    }
    
    if(this->curr_size == 0) {
        this->ves[1] = data;
        this->curr_size = 1;
    }
    else {
        // 自底向上方法
        this->curr_size++;
        this->ves[this->curr_size] = data;
        int i = (int)this->curr_size;
        while(i > 1 && ves[i] < ves[i/2]) {
            this->swap(&this->ves[i], &this->ves[i/2]);
            i /= 2;
        }
    }
    return true;
}

template <class T>
const T Heap<T>::pop_max(void){
    T top = this->ves[1];
    this->ves[1] = this->ves[this->curr_size];
    this->ves[this->curr_size] = 0;
    this->curr_size--;
    
    for(int i = 1, ch = i * 2; ch <= this->curr_size; i = ch, ch *= 2){
        // 第二个子节点较大
        if(ch + 1 <= this->curr_size && this->ves[ch] < this->ves[ch + 1]){
            ch++;
        }
        if(this->ves[ch] < this->ves[i]){
            break;
        }
        // 与子节点交换位置
        this->swap(&this->ves[i], &this->ves[ch]);
    }

    return top;
}

template <class T>
const T Heap<T>::pop_min(void){
    T top = this->ves[1];
    this->ves[1] = this->ves[this->curr_size];
    this->ves[this->curr_size] = 0;
    this->curr_size--;
    
    for(int i = 1, ch = i * 2; ch <= this->curr_size; i = ch, ch *= 2){
        // 第二个子节点较小
        if(ch + 1 <= this->curr_size && this->ves[ch] > this->ves[ch + 1]){
            ch++;
        }
        if(this->ves[ch] > this->ves[i]){
            break;
        }
        // 与子节点交换位置
        this->swap(&this->ves[i], &this->ves[ch]);
    }
    
    return top;
}

template <class T>
const T Heap<T>::get_top(){
    return this->ves[1];
}

template <class T>
const bool Heap<T>::Push(const T data){
    this->push_max(data);
    return true;
}

template <class T>
const T Heap<T>::Pop(){
    return this->pop_max();
}

template <class T>
const T Heap<T>::GetTop(){
    return this->get_top();
}

template <class T>
void Heap<T>::Display(void) const {
    std::cout<<"Display: "<<std::endl;
    for(int i = 1;i < this->curr_size + 1; i++){
        std::cout<<"ves["<<i<<"]: "<<this->ves[i]<<"\t";
    }
    std::cout<<std::endl;
    return;
}

#endif /* HEAP_HPP */
