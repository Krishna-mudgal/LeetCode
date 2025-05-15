#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/triangle/description/

class Solution { // top down
public:
    vector<vector<int> >dp;
    int n;

    int helper(vector<vector<int> > &triangle, int idx, int c){ // c -> is current coloum
        if(idx == triangle.size()) return 0;

        if(dp[idx][c] != 1e5) return dp[idx][c];
        else{
            // hr bar i have two choices i can go with c or c + 1 so i will go with both of them and after exploring i will take min of them
            int ans = triangle[idx][c] + min(helper(triangle, idx + 1, c), helper(triangle, idx + 1, c + 1));

            return dp[idx][c] = ans;
        }

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.clear();
        dp.resize(n, vector<int> (n, 1e5));

        dp[0][0] = triangle[0][0];

        return triangle[0][0] + min(helper(triangle, 1, 0), helper(triangle, 1, 1));
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { // bottom up
        int n = triangle.size();

        vector<vector<int> > dp(n, vector<int> (n, INT_MIN));

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
                else if(j == triangle[i].size() - 1) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                else dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < triangle[n - 1].size(); i++) ans = min(ans, dp[n - 1][i]);

        return ans;

    }
};