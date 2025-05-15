#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> row, col;

        for(int i = 0; i < m; i++){
            int c= 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) c++;
            }
            row.push_back(c);
        }

        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < m; j++){
                if(grid[j][i] == 1) c++;
            }

            col.push_back(c);
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    if(row[i] > 1 || col[j] > 1) ans++;
                }
            }
        }

        return ans;

    }
};

// more optimized

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> row(m, 0), col(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    if(row[i] > 1 || col[j] > 1) ans++;
                }
            }
        }

        return ans;

    }
};