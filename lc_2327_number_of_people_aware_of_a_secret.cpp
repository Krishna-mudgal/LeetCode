#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09

class Solution {
public:

    int mod = 1000000007;

    void solve(int n, int delay, int forget, int currday, vector<vector<int>> &ans) {
        if(n < currday) return ;    

        int person = 0;
        for(int i = 1; i < currday; i++) {
            if(currday - ans[i][0] >= forget) ans[i][1] = 0;
            if(currday - ans[i][0] >= delay && ans[i][1] != INT_MAX) person += ans[i][1];

            person %= mod;

        }
        ans[currday][1] = person;
        ans[currday][0] = currday;

        solve(n, delay, forget, currday + 1, ans);

    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> ans(n + 1, vector<int> (2, INT_MAX));
        ans[1][0] = 1;
        ans[1][1] = 1;
        solve(n, delay, forget, 2, ans);
        int finalAns = 0;
        for(int i = 0; i < n + 1; i++) {
            if(ans[i][1] != INT_MAX) finalAns += ans[i][1];
            finalAns %= mod;
        }

        return finalAns;
    }
};