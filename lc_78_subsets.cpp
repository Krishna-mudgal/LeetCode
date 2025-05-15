#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subsets/description/

class Solution {
    public:
    
        int n;
    
        void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> v, int idx){
            if(idx == n) {
                ans.push_back(v);
                return;
            }
    
            helper(nums, ans, v, idx + 1); // not take
            v.push_back(nums[idx]);
            helper(nums, ans, v, idx + 1); // take
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            n = nums.size();
            vector<int> v;
            vector<vector<int>> ans;
    
            helper(nums, ans, v, 0);
    
            return ans;
        }
    };