#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    class Node{
    public:
        int val;
        Node*next;
        Node *prev;

        Node(int val){
            this -> next = NULL;
            this -> prev = NULL;
            this -> val = val;
        }
    };
    
    int ms, s;
    Node *f, *b;
    MyCircularDeque(int k) {
        ms = k;
        s = 0;
        f = NULL;
        b = NULL;
    }
    
    bool insertFront(int value) {
        if(s < ms){
            Node *t = new Node(value);
            if(s == 0) f = b = t;
            else{
                t -> next = f;
                f -> prev = t;
                f = t;
            }
            s++;
            return true;
        }
        else return false;
    }
    
    bool insertLast(int value) {
        if(s < ms){
            Node *t = new Node(value);
            if(s == 0) f = b = t;
            else{
                b -> next = t;
                t -> prev = b;
                b = t;
            }
            s++;
            return true;
        }
        else return false;
    }
    
    bool deleteFront() {
        if(s > 0){
            Node *t = f;
            if(s == 1) f = b = NULL;
            else{
                f = f -> next;
                f -> prev = NULL;
            }
            s--;
            delete(t);
            return true;
        }
        else return false;
    }
    
    bool deleteLast() {
        if(s > 0){
            Node *t = b;
            if(s == 1) f = b = NULL;
            else{
                 b = b -> prev;
                b -> next = NULL;
            }
            delete(t);
            s--;
            return true;
        }
        else return false;
    }
    
    int getFront() {
        if(s > 0) return f -> val;
        else return -1;
    }
    
    int getRear() {
        if(s > 0) return b -> val;
        else return -1;
    }
    
    bool isEmpty() {
        if(s == 0) return true;
        else return false;
    }
    
    bool isFull() { 
        if(s == ms) return true;
        else return false;
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