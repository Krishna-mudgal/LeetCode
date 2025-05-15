#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) { // bottom up
        int n = nums.size();
        dp.clear();
        dp.resize(n + 5, -1);

        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);

        // starts with 0 and go till last - 1
        dp[0] = nums[0];
        for(int i = 1; i < n - 1; i++){
            // we have two choices pick current and look for idx + 2 or skip current and pick idx + 1
            if(i > 1) dp[i] = max(nums[i] + dp[i - 2], 0 + dp[i - 1]);
            else dp[i] = max(nums[i], dp[i - 1]);
        }

        int ans1 = dp[n - 2];

        dp.clear();
        dp.resize(n + 5, -1);
        
        // starts with 1 and go till last
        dp[1] = nums[1];
        for(int i = 2; i < n; i++){ // we have two choices pick current and look for idx + 2 or skip current and pick idx + 1
            if(i > 2) dp[i] = max(nums[i] + dp[i - 2], 0 + dp[i - 1]);
            else dp[i] = max(nums[i], dp[i - 1]);
        }

        int ans2 = dp[n - 1];
        
        return max(ans1, ans2);
    }
};

class Solution {
public:
    vector<int> dp;
    int helper(vector<int> &nums, int idx, int &end){ // top down
        if(idx > end) return 0;

        if(dp[idx] != -1) return dp[idx];
        else return dp[idx] = max(nums[idx] + helper(nums, idx + 2, end), 0 + helper(nums, idx + 1, end));

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n + 5, -1);

        int x1 = n - 1, x2 = n - 2;

        int ans1 = helper(nums, 0, x2);

        dp.clear();
        dp.resize(n + 5, -1);
        int ans2 = helper(nums, 1, x1);

        return max({ ans1, ans2, nums[n - 1] });
    }
};