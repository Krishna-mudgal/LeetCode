#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:

    vector<vector<vector<int>>> dp;
    int solve(vector<int> &prices, int k, int idx, int buyAllowed){
        if(idx >= prices.size() || k == 0) return 0;
        if(dp[idx][buyAllowed][k] != -1) return dp[idx][buyAllowed][k];

        if(buyAllowed == 1) {
            int skip = solve(prices, k, idx + 1, 1);
            int take = solve(prices, k, idx + 1, 0) - prices[idx]; // buy kra mtlv paisa diya h to profit m se minus hihoga

            return dp[idx][buyAllowed][k] = max(skip, take);
        } else {
            int skip = solve(prices, k, idx + 1, 0);
            int take;

            if(k > 0) {
                take = solve(prices, k - 1, idx + 1, 1) + prices[idx]; // sell kra h to profit m add hihoga
            } else take = prices[idx];

            return dp[idx][buyAllowed][k] = max(skip, take);
        }

    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>> (2, vector<int>(k + 1, -1)));
        return solve(prices, k, 0, 1);
    }
};