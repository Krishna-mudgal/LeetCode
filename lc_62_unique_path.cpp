#include <bits/stdc++.h>
using namespace std;

class Solution { // top down
public:
    int helper(int m, int n, int x, int y, vector<vector<int> > &dp){
        if(x >= m || y >= n) return 0;
        if(x == m - 1 && y == n - 1) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        else return dp[x][y] = helper(m, n, x + 1, y, dp) + helper(m, n, x, y + 1, dp);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int> (n, -1));
        return helper(m, n, 0, 0, dp);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) { // bottom up
        vector<vector<int> > dp(m, vector<int> (n, -1));
        dp[0][0] = 1;

        // I HAVE TO CALCULAE WAYS NOT STEPS

        for(int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1]; // filling first row

        for(int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0]; // filling first coloums

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // m yha to upr se askta hu i,j pr that is i-1,j ya fir piche se that is i,j-1
            }
        }

        return dp[m - 1][n - 1];

    }
};