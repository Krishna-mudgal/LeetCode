#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30

class CustomStack {
public:
    vector<int> v;
    int mx;
    CustomStack(int maxSize) {
        v.clear();
        mx = maxSize;
    }
    
    void push(int x) {
        if(v.size() < mx){
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.size() > 0){
            int ans = v.back();
            v.pop_back();
            return ans;
        }
        else return -1;
    }
    
    void increment(int k, int val) {
        int s = v.size();
        int x = min(k, s);

        for(int i = 0; i < x; i++) v[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */