#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/score-after-flipping-matrix/description/

class Solution {
    public:
    
        int calc(vector<vector<int>> &v){
            int ans = 0;
    
            for(int i = 0; i < v.size(); i++){
                int x = 1;
                for(int j = v[i].size() - 1; j >= 0; j--){
                    ans += x*v[i][j];
                    x *= 2;
                }
            }
            return ans;
        }
    
        void print(vector<vector<int>> &v){
            for(auto i : v){
                for(auto j : i) cout << j << " ";
    
                cout << endl;
            }
        }
    
        int matrixScore(vector<vector<int>>& grid) {
    
            // greedy is : 
            // If the first number in the row is 0, flip the row. If the count of 0 in the col is greater than the count of 1, flip the col.
    
            int m = grid.size(), n = grid[0].size();
            int ans = 0;
    
            for(int i = 0; i < m; i++){
                if(grid[i][0] == 0){
                    for(int j = 0; j < n; j++){
                        if(grid[i][j] == 0) grid[i][j] = 1;
                        else grid[i][j] = 0;
                    }
                }
            }
    
            ans = max(ans, calc(grid));
            // print(grid);
    
            for(int i = 0; i < n; i++){
                int noo = 0, noz = 0;
                for(int j = 0; j < m; j++){
                    if(grid[j][i] == 0) noz++;
                    else noo++;
                }
    
                if(noo < noz) {
                    for(int j = 0; j < m; j++){
                        if(grid[j][i] == 0) grid[j][i] = 1;
                        else grid[j][i] = 0;
                    }
                }
            }
    
            // print(grid);
    
            ans = max(ans, calc(grid));
    
            return ans;
        }
    };