#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-decreasing-subsequences/

class Solution {
public:

    void helper(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &v){
        if(v.size() >= 2) ans.push_back(v);

        unordered_set<int> st;
        for(int i = idx; i < nums.size(); i++){
            if((st.find(nums[i]) == st.end()) && (v.size() == 0 || nums[i] >= v.back())){ // if nums[i] is not repetitive and v is empty or nums[i] >= last element that we have inserted then do the following
                v.push_back(nums[i]); // insert it
                st.insert(nums[i]);
                helper(nums, ans, i + 1, v); // call helper function
                v.pop_back(); // back track it
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(nums, ans, 0, v);

        return ans;
    }
};