#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lru-cache/description/

class Page{
public: 
    int key;
    int val;
    Page *prev;
    Page *next;

    Page(int &key, int &val) {
        this -> key = key;
        this -> val = val;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

class Frame{
public: 

    int n;
    unordered_map<int, Page*> mp;
    int c_size;
    Page *head;
    Page *tail;
    Frame(int &n) {
        this -> n = n;
        this -> c_size = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }

    int get(int &key) {
        if(mp.find(key) != mp.end()) {
            Page *temp = mp[key];

            if(temp != head && temp != tail) { // means temp is in middle
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;

                temp -> next = head;
                temp -> prev = NULL;
                head -> prev = temp;
                head = temp;
            } else if(temp != head) { // if temp is tail
                tail = temp -> prev;
                tail -> next = NULL;

                temp -> next = head;
                head -> prev = temp;
                temp -> prev = NULL;
                head = temp;
            } // else temp will be head so that's okay

            return mp[key] -> val;
        } else return -1;
    }

    void put(int &key, int &val) {
        if(mp.find(key) != mp.end()) { // just need to place key at top            
            Page *temp = mp[key];
            temp -> val = val;
            if(temp != head && temp != tail) { // means temp is in middle
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;

                temp -> next = head;
                temp -> prev = NULL;
                head -> prev = temp;
                head = temp;
            } else if(temp != head) { // if temp is tail
                tail = temp -> prev;
                tail -> next = NULL;

                temp -> next = head;
                head -> prev = temp;
                temp -> prev = NULL;
                head = temp;
            } // else temp will be head so that's okay

        } else { // need to add key value pair
            Page *p = new Page(key, val);
            mp[key] = p;
            if(c_size == n) { // needed to remove last one
                mp.erase(tail -> key);
                tail = tail -> prev;
                if(tail) tail -> next = NULL;
                c_size--;
            }
            
            if(c_size == 0) {   
                head = p;
                tail = p;
                c_size++;
            } else {
                p -> next = head;
                head -> prev = p;
                head = p;
                c_size++;
            }
        }
    }

};

class LRUCache {
public:
    Frame *f;
    LRUCache(int capacity) {
        f = new Frame(capacity);
    }
    
    int get(int key) {
        return f -> get(key);
    }
    
    void put(int key, int value) {
        f -> put(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */