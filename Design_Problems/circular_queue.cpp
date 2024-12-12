#include<bits/stdc++.h>
using namespace std;
class MyCircularDeque {
public:
    int size;
    int capacity;
    int front;
    int rear;
    vector<int>q;
    MyCircularDeque(int k) {
        this->q=vector<int>(k,-1);
        this->capacity=k;
        this->size=0;
        this->front=0;
        this->rear=capacity-1;
    }
    //while inserting at start we move our f towards left hence -1
    bool insertFront(int value) {
        if (isFull()) return false;
        // Move front backward
        this->front = (this->front - 1 + capacity) % capacity;
        q[this->front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        size++;
        this->rear=(this->rear+1)%capacity;
        q[this->rear]=value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        this->front = (this->front + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        this->rear = (this->rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0){
            return -1;
        }
        return q[front];
    }
    
    int getRear() {
        if(size==0){
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==capacity){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */