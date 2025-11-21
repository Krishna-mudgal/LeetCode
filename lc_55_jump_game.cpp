#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game/

class Solution { // D.P. solution
public:
    
    vector<int> dp;
    bool helper(vector<int> &nums, int idx) {
        if(idx >= nums.size()) return false;
        if(idx == nums.size() - 1) return true;
        if(dp[idx] != -1) return dp[idx];

        int ans = 0;
        int jump = nums[idx];
        for(int i = 1; i <= jump; i++) {
            if(helper(nums, idx + i)) {
                ans = 1;
                break;
            }
        }

        return dp[idx] = ans;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n + 1, -1);
        return helper(nums, 0);
    }
};

class Solution { // greedy approach
public:
    bool canJump(vector<int>& nums) {
        // we will maintain maxReachable variable;
        
        int n = nums.size();
        int maxReachable = 0;

        for(int i = 0; i <= maxReachable; i++) {
            if(i == n - 1) return true;
            maxReachable = max(maxReachable, i + nums[i]);
        }

        return false;
    }
};