#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        while(n > 1){
            int x = q.front();
            q.pop();
            q.push(x);
            n--;
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int n = q.size();
        while(n > 1){
            int x = q.front();
            q.pop();
            q.push(x);
            n--;
        }
        int ans = q.front();
        q.push(q.front());
        q.pop();
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */