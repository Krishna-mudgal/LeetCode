#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    long long helper(int stair, vector<int> &cost, vector<int> &dp){ // topdown
        if(stair > cost.size()) return INT_MAX;
        if(stair == cost.size()) return 0;

        if(dp[stair] != -1) return dp[stair];
        else{
            int ans;
            ans = min(cost[stair] + helper(stair + 1, cost, dp), cost[stair] + helper(stair + 2, cost, dp));

            return dp[stair] = ans;
        }

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};

// bottum up

    class Solution {
    public:

        int minCostClimbingStairs(vector<int>& cost) { // bottom up
            vector<int> dp(cost.size() + 1, -1);
            int n = cost.size();
            dp[0] = cost[0], dp[1] = cost[1];

            for(int i = 2; i < n; i++){
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }

            dp[n] = 0 +  min(dp[n - 1], dp[n - 2]); // VIMP

            return dp[n];

        }
    };