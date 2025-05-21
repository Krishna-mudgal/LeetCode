#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution { // T.C. = O(2^n)
public:

    void helper(vector<int> &nums, int idx, int last, int &ans, int len){
        if(idx >= nums.size()){
            ans = max(ans, len);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(last < nums[i]){
                helper(nums, i + 1, nums[i], ans, len + 1);
            }
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int len = 0, last = INT_MIN, ans = 0;
        helper(nums, 0, last, ans, 0);

        return ans;
    }
};