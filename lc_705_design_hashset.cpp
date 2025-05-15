#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-hashset/description/

class MyHashSet { // approach 1
public:
    vector<int> v;
    MyHashSet() {
        v.resize(1000001, -1);
    }
    
    void add(int key) {
        v[key] = 0;
    }
    
    void remove(int key) {
        v[key] = -1;
    }
    
    bool contains(int key) {
        return v[key] == 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

class MyHashSet { // approach - 2
public:
    vector<int> v;
    MyHashSet() {

    }
    
    void add(int key) {
        for(int e : v) if(e == key) return;

        v.push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0; i < v.size(); i++){
            if(v[i] == key) {
                swap(v[i], v[v.size() - 1]);
                v.pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        for(int e : v) if(e == key) return true;

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

class MyHashSet { // approach - 3
public:
    unordered_set<int> s;
    MyHashSet() {

    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        if(s.find(key) != s.end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */