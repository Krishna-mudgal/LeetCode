#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28

class Solution {
public:
    int helper(vector<vector<int>> &g, int r, int c){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] == 0) return 0;

        int fish = g[r][c];
        g[r][c] = 0;

        return fish + helper(g, r + 1, c) + helper(g, r - 1, c) + helper(g, r, c + 1) + helper(g, r, c - 1);
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] >= 1) ans = max(ans, helper(grid, i, j));
            }
        }

        return ans;
    }
};