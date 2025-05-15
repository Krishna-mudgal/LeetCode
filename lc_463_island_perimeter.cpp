#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    if(i == 0) ans++; // if island is present at first row then 
                    else if(grid[i - 1][j] == 0) ans++;

                    if(i == n - 1) ans++;
                    else if(grid[i + 1][j] == 0) ans++;

                    if(j == grid[i].size() - 1) ans++;
                    else if(grid[i][j + 1] == 0) ans++;

                    if(j == 0) ans++;
                    else if(grid[i][j - 1] == 0) ans++;   

                }
            }
        }

        return ans;

    }
};