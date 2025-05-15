#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/description/


class Solution { // top down
public:
    int helper(int x, int y, vector<vector<int> >&obstacleGrid, vector<vector<int> > &dp){
        if(x < 0 || y < 0) return 0;
        if(x == 0 && y == 0) {
            if(obstacleGrid[x][y] == 1) return 0;
            else return 1;
        }

        if(dp[x][y] != -1) return dp[x][y];

        if(obstacleGrid[x][y] == 1) return dp[x][y] = 0;

        return dp[x][y] = helper(x - 1, y, obstacleGrid, dp) + helper(x, y - 1, obstacleGrid, dp);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // if(m == 1 && n == 1){
        //     if(obstacleGrid[0][0] == 0) return 1;
        //     else return 0;
        // }
        vector<vector<int> > dp(m, vector<int> (n, -1));

        return helper(m - 1, n - 1, obstacleGrid, dp);
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {// bottom up
        int m = obstacleGrid.size(), n = obstacleGrid[0].size(); // m -> row, n -> coloums
        vector<vector<int> > dp(m, vector<int> (n, -1));

        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        // in first row we can travel by only 1 way that is going right at every step and if there is any obstacle then there is no way we can reach remaining row after obstacle so fill it's previous cell bcs if there is any obstacle then it's value wiil already be 0
        for(int i = 1; i < n; i++) {
            if(obstacleGrid[0][i] == 1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i - 1];
        }

         // in first coloum we can travel by only 1 way that is going dowm at every step and if there is any obstacle then there is no way we can reach remaining coloum after obstacle so fill it's previous cell bcs if there is any obstacle then it's value wiil already be 0 
        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i - 1][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // // m yha to upr se askta hu i,j pr that is i-1,j ya fir piche se that is i,j-1 if there is no obstacle
            }
        }

        return dp[m - 1][n - 1];
    }
};