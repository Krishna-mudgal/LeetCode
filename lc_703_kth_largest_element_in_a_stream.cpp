#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;
    // in pq, we have to maintain k largest element so that at top we always get kth largest element
    KthLargest(int k, vector<int>& nums) {
        x = k;

        // first insert k elements in pq, then check if pq.top() < new_element if yes then insert it because we have to maintain kth largest element

        for(int i : nums){
            if(pq.size() < k) pq.push(i);
            else if(pq.top() < i){
                pq.pop();
                pq.push(i);
            }
        }
    }
    
    int add(int val) {
        // check if pq.top < new element if yes then insert it because we have to maintain kth largest element

        if(pq.size() < x) pq.push(val);
        else if(pq.top() < val){
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */