#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    vector<pair<int, int>> v;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == key) {
                v[i].second = value;
                return;
            }
        }
        v.push_back({key, value});
    }
    
    int get(int key) {
        for(auto p : v){
            if(p.first == key) return p.second;
        }

        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == key){
                swap(v[i], v[v.size() - 1]);
                v.pop_back();
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class MyHashMap {// approach 2
public:
    vector<long long > v;
    MyHashMap() {
        v.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        v[key] = value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */