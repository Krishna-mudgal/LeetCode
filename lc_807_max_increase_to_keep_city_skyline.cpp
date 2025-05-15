#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n), col(n); // hr row ka max row vector m aur hr column ka max col vector m

        for(int i = 0; i < n; i++){
            int x = INT_MIN;
            for(int j = 0; j < n; j++){
                x = max(x, grid[i][j]);
            }
            row[i] = x;
        }

        for(int i = 0; i < n; i++){
            int x = INT_MIN;
            for(int j = 0; j < n; j++){
                x = max(x, grid[j][i]);
            }
            col[i] = x;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = grid[i][j];
                int y = min(row[i], col[j]);
                ans += y - x;
            }
        }

        return ans;
    }
};