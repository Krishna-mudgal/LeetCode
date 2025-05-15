#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

class Solution {
public:

    bool helper(queue<int> q, vector<int> &nums){
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(q.front() != nums[i]) return false;
            
            q.push(q.front());
            q.pop();
        }

        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());

        queue<int> q;
        for(int i : v) q.push(i);

        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
           
            if(helper(q, nums)) return true;
        }
        
        return false;
    }
};