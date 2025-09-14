#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/description/

class Solution { // solution with no dp
public:
    // vector<vector<int>> dp
    int solve(vector<int> &nums, int &target, int curr_sum, int idx) { // T.C. = O(2^n)
        if(idx >= nums.size()) {
            if(curr_sum == target) {
                return 1;
            } else return 0;
        }

        // by adding one of the symbols '+' and '-' before each integer in nums, hence no scope for not take
        // // not take
        // int x = 0;
        // x += solve(nums, target, curr_sum, idx + 1); 

        // take
        int a = solve(nums, target, curr_sum + nums[idx], idx + 1);
        int b = solve(nums, target, curr_sum - nums[idx], idx + 1);

        return a + b;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        string s = "";
        unordered_set<string> st;
        return solve(nums, target, 0, 0);
    }
};


class Solution { // T.C. = O(2000*n)
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums, int &target, int curr_sum, int idx) {
        if(idx >= nums.size()) {
            if(curr_sum == target) {
                return 1;
            } else return 0;
        }

        if(dp[curr_sum + 1000][idx] != -1) return dp[curr_sum + 1000][idx];

        // by adding one of the symbols '+' and '-' before each integer in nums, hence no scope for not take
        // // not take
        // int x = 0;
        // x += solve(nums, target, curr_sum, idx + 1); 

        // take
        int a = solve(nums, target, curr_sum + nums[idx], idx + 1);
        int b = solve(nums, target, curr_sum - nums[idx], idx + 1);

        return dp[curr_sum + 1000][idx] = a + b;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(2005, vector<int> (nums.size() + 1, -1));
        return solve(nums, target, 0, 0);
    }
};