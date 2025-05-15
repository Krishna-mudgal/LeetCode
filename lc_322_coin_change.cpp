#include <bits/stdc++.h>
using namespace std;

class Solution { // top down
public:
    vector<int> dp;

    long long helper(vector<int> &coins, int tar){
        if(tar == 0) return 0;

        if(dp[tar] != -1) return dp[tar];
        else{
            long long ans = INT_MAX;
            for(int i = 0; i < coins.size(); i++){
                if(tar - coins[i] < 0) continue;
                ans = min(ans, helper(coins, tar - coins[i]));
            }
            if(ans == INT_MAX) return dp[tar] = INT_MAX; // means no such combination of coins exisits
            else return dp[tar] = 1 + ans; // 1 denotes we used 1 coin so no of coins increase by 1
        }   
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(amount + 1, -1);
        long long ans = helper(coins, amount);

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};

class Solution { // bottom up
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){

            int ans = INT_MAX;
            for(int j = 0; j < n ; j++){
                if(i - coins[j]  < 0) continue;

                ans = min(ans, dp[i - coins[j]]);
            }

            if(ans == INT_MAX) dp[i] = INT_MAX;
            else dp[i] = 1 + ans;
        }

        if(dp[amount] == INT_MAX) return -1;
        else return dp[amount];

    }
};