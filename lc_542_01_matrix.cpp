#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        /*  
            1. getting TLE with bfs for each 1 approach and calculating nearest 0 for each cell
            2. so this time we will start with 0s and gradually update nearest dist for each 1 from them
        */

        vector<vector<int>> ans(n, vector<int>(m, -2));
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int dist = 0;
        while(!q.empty()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                auto p = q.front();
                q.pop();        

                int x = p[0], y = p[1];
                if(mat[x][y] == 1) ans[x][y] = dist;

                for(auto dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(x_ >= 0 && y_ >= 0 && x_ < n && y_ < m && !visited[x_][y_]) {
                        q.push({x_, y_});
                        visited[x_][y_] = true;
                    }
                }
            }
            dist++;
        }

        

        return ans;
    }
};