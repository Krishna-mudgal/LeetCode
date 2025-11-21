#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    vector<int> dp = vector<int>(5*10e4 + 1, -1);
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size()) return false;
        if(arr[start] == 0) return true;
        if(dp[start] != -1) return dp[start];
        
        dp[start] = 0;
        return dp[start] = (canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]));
    }
};