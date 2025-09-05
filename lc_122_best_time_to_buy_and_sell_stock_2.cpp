#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:

    vector<vector<int>> dp;
    int solve(vector<int> &prices, int idx, int buyAllowed) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][buyAllowed] != -1) return dp[idx][buyAllowed] ;

        if(buyAllowed == 1) {
            int skip = solve(prices, idx + 1, 1);

            int take = solve(prices, idx + 1, 0) - prices[idx]; // buy kiya h to profit m se minus hoga

            return dp[idx][buyAllowed] = max(skip, take);
        }
        else {
            int skip = solve(prices, idx + 1, 0);
            int take = solve(prices, idx + 1, 1) + prices[idx]; // sell kiya h to profit m add hoga

            return dp[idx][buyAllowed] = max(skip, take);
        }
    }

    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int> (2, -1));
        return solve(prices, 0, 1);
    }
};