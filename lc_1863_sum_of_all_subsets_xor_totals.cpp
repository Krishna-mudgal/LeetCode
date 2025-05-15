#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

class Solution {
public:

    void helper2(vector<int> &v, int &ans){
        
        int x = v[0];
        for(int i = 1; i < v.size(); i++) {
            x ^= v[i];
        }

        ans += x;
    }

    void helper(vector<int> &nums, vector<int> v, int idx, int &ans){
        if(idx == nums.size()) return;

        for(int i = idx; i < nums.size(); i++){
            v.push_back(nums[i]);
            helper2(v, ans);
            helper(nums, v, i + 1, ans);
            v.pop_back();
        }

    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> v;
        helper(nums, v, 0, ans);
        return ans;
    }
};

class Solution {
    public:
    
        void helper(vector<int> &nums, int &ans, int idx, int x){
            if(idx == nums.size()) {
                ans += x;
                return;
            }
    
            helper(nums, ans, idx + 1, x); // take
            helper(nums, ans, idx + 1, x ^ nums[idx]); // not take
        }
    
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size();
    
            int ans = 0;
            helper(nums, ans, 0, nums[0]);
    
            return ans;
        }
    };