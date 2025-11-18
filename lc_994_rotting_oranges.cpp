#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/

class Solution { // o(n*m)
public:

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0, fresh = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        // Here all rotten oranges will simulataneously transform fresh orange to a rotten orange and therefore we will use bfs

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) { // O(n*m)
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                } else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int cnt = 0;
        while(!q.empty()) { // O(n*m) + O(n*m*4) = O(n*m)
            ans++;
            int x = q.size();
            for(int i = 0; i < x; i++) {
                auto p = q.front();
                q.pop();

                for(auto dir : directions) {
                    int x_ = p.first + dir[0];
                    int y_ = p.second + dir[1];
            
                    if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && !visited[x_][y_] && grid[x_][y_] == 1) {
                        grid[x_][y_] = 2;
                        visited[x_][y_] = true;
                        cnt++;
                        q.push({x_, y_});
                    }
                }
            }
        }

        if(cnt != fresh) return -1;

        return ans - 1;
    }
};