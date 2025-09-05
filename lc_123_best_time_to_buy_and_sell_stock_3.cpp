#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:

    vector<vector<vector<int>>> dp;
    int solve(vector<int> &prices, int idx, int buyAllowed, int cnt) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][buyAllowed][cnt] != -1) return dp[idx][buyAllowed][cnt];

        if(buyAllowed) {
            int skip = solve(prices, idx + 1, 1, cnt);
            int take = solve(prices, idx + 1, 0, cnt) - prices[idx];
            
            return dp[idx][buyAllowed][cnt] = max(skip, take);
        } else {
            int skip = solve(prices, idx + 1, 0, cnt);
            int take;
            if(cnt == 1) {
                take = prices[idx];
            } else take = solve(prices, idx + 1, 1, cnt + 1) + prices[idx];

            return dp[idx][buyAllowed][cnt] = max(skip, take);
        }

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>> (2, vector<int> (3, -1)));

        return solve(prices, 0, 1, 0);
    }
};