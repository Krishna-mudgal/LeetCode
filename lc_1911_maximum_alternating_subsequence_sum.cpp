#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/

class Solution {
public:
    vector<pair<long long, long long>> dp;
    
    long long solve(vector<int> &nums, int idx, bool flag){
        if(idx >= nums.size()) return 0;

        if(flag && dp[idx].first != -1) return dp[idx].first;
        else if(!flag && dp[idx].second != -1) return dp[idx].second;

        long long skip = solve(nums , idx + 1, flag); // skip m flag jese tha wesa hi rhega kyu ki hmne element skip kiya h ti iski jgh pr next element a jyga
        long long val = nums[idx];
        if(!flag) val = -val;

        long long take = solve(nums, idx + 1, !flag) + val; // or take kiya h to alternate lena h to next wala negative hi hojyga isliye !flag

        return (flag) ? (dp[idx].first = max(take, skip)) : (dp[idx].second = max(take, skip));

    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, {-1, -1});

        // if flag = true -> + -> even
        // else - -> odd

        return solve(nums, 0, true); 
    }
};
