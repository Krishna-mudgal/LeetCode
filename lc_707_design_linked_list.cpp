#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/design-linked-list/description/

class Node{
public :
    int val;
    Node *next;

    Node(int val){
        this -> val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    int size;
    Node *head;
    Node *tail;
    MyLinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        else {
            int x = 0;
            Node *t = head;
            while(t){
                if(x == index) return t -> val;
                x++;
                t = t -> next;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node *t = new Node(val);
        if(size == 0){
            head = t;
            tail = t;
        }
        else{
            t -> next = head;
            head = t;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node *t = new Node(val);
        if(size == 0){
            tail = t;
            head = t;
        }
        else{
            tail -> next = t;
            tail = t;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == size) return addAtTail(val);
        else if(index == 0) return addAtHead(val);
        else if(index < 0 || index > size) return;

        int x = 0;
        Node *t2 = new Node(val);
        Node *t = head;
        while(x < index - 1){
            t = t -> next;
            x++;
        }

        t2 -> next = t -> next;
        t -> next = t2;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0) {
            head = head -> next;
            size--;
            return;
        }

        int x = 0;
        Node *t = head;
        while(x < index - 1){
            x++;
            t = t -> next;
        }
        if(index == size - 1){
            tail = t;
            t -> next = NULL;
        }
        else t -> next = t -> next -> next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */