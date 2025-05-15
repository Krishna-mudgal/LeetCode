#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray { // time : O(n), space : O(1);
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        v = nums;
        int n = v.size();
        for(int i = 1; i < n; i++) v[i] += v[i - 1];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return v[right];
        else return v[right] - v[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */