#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/

class Solution { // top down approach
public:
    int helper(vector<vector<int>>& grid, int x, int y, int &m, int &n, vector<vector<int> > &dp){
        if(x >= m || y >= n) return INT_MAX;

        if(x == m - 1 && y == n - 1) return grid[x][y];

        if(dp[x][y] != -1) return dp[x][y];
        else{   
            return dp[x][y] = grid[x][y] + min( helper(grid, x + 1, y, m, n, dp), helper(grid, x, y + 1, m, n, dp));

        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int> (n, -1));
        return helper(grid, 0, 0, m, n, dp);
    }
};

class Solution { // bottom up
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); // m rows n coloum
        vector<vector<int> > dp(m, vector<int> (n, -1));
        dp[0][0] = grid[0][0];

        for(int i = 1; i < n; i++){ // filling coloum wise
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for(int i = 1; i < m; i++){ // filling row wise
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];

    }
};