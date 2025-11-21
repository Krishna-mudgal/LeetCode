#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/frog-jump/description/

class Solution {
public:
    vector<vector<int>> dp;
    bool helper(vector<int> &stones, unordered_map<int, int> &mp, int unit, int lastJump) {
        if(lastJump <= 0) return false; // frog can jump only in forward direction
        if(unit > stones.back()) return false;
        if(unit == stones.back()) return true; // reached last stone
        if(mp.find(unit) == mp.end()) return false; // at this unit there is water
        int idx = mp[unit];
        if(dp[idx][lastJump] != -1) return dp[idx][lastJump];

        dp[idx][lastJump] = 0;
        return dp[idx][lastJump] = (helper(stones, mp, unit + lastJump - 1, lastJump - 1) || helper(stones, mp, unit + lastJump, lastJump) || helper(stones, mp, unit + lastJump + 1, lastJump + 1));
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[stones[i]] = i;
        dp.resize(n, vector<int> (n, -1));
        return helper(stones, mp, stones[0] + 1, 1);
    }
};