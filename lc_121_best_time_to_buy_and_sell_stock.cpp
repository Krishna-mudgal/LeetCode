#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> reverse_max(n);
        int maxi = prices[n - 1];

        for(int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, prices[i]);
            reverse_max[i] = maxi;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, reverse_max[i] - prices[i]);
        }

        return ans;
    }
};