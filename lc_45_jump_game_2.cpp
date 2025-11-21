#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/description/

class Solution { // top-down
public:

    vector<long long> dp;
    long long helper(vector<int> &nums, int idx) {
        if(idx >= nums.size()) return INT_MAX;
        if(idx == nums.size() - 1) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;
        for(int i = 1; i <= nums[idx]; i++) {
            long long x = 1 + helper(nums, idx + i);
            if(ans > x) {
                ans = x; 
            }
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return helper(nums, 0);
    }
};