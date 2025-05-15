#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    void mark(vector<vector<char>>& grid, vector<vector<bool> > &check, int x, int y, int &m, int &n){
        if(x >= m || y >= n || !check[x][y]) return;

        check[x][y] = false;

        if(x + 1 < m && check[x + 1][y] && grid[x + 1][y] == '1') mark(grid, check, x + 1, y, m, n);
        if(x - 1 >= 0 && check[x - 1][y] && grid[x - 1][y] == '1') mark(grid, check, x - 1, y, m, n);
        if(y + 1 < n && check[x][y + 1] && grid[x][y + 1] == '1') mark(grid, check, x, y + 1, m, n);
        if(y - 1 >= 0 && check[x][y - 1] && grid[x][y - 1] == '1') mark(grid, check, x, y - 1, m, n);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool> > check(m, vector<bool> (n, true));
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && check[i][j]){
                    ans++;
                    mark(grid, check, i, j, m, n);
                }
            }
        }

        return ans;
    }
};