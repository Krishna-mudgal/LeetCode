#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=daily-question&envId=2024-12-18

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(prices[j] <= prices[i]){
                    ans.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if(ans.size() != i + 1) ans.push_back(prices[i]);
        }

        return ans;
    }
};