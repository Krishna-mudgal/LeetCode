#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/magic-squares-in-grid/description/

class Solution {
    public:
    
        bool check(vector<vector<int>> &g, int r, int c){
            int r_1 = 0, r_2 = 0, r_3 = 0, c_1 = 0, c_2 = 0, c_3 = 0, d_1 = 0, d_2 = 0;
            vector<int> v(10, 0);
            for(int i = r; i < r + 3; i++){
                for(int j = c; j < c + 3; j++){ 
                    
                    if(g[i][j] > 9 || v[g[i][j]] == 1 || g[i][j] < 1) return false;
                    else v[g[i][j]]++;
    
                    if(i == r) r_1 += g[i][j];
                    if(i == r + 1) r_2 += g[i][j];
                    if(i == r + 2) r_3 += g[i][j];
    
                    if(j == c) c_1 += g[i][j];
                    if(j == c + 1) c_2 += g[i][j];
                    if(j == c + 2) c_3 += g[i][j];
    
                    if(i - r == j - c) d_1 += g[i][j];
                    if(i - r + j - c == 2) d_2 += g[i][j];
                }
            }
    
            // cout << r << " " << c << " " << r_1 << " " << r_2 << " " << r_3 << " " << c_1 << " " << c_2 << " " << c_3 << " " << d_1 << " " << d_2 << endl;
    
            return r_1 == r_2 && r_2 == r_3 && r_3 == c_1 && c_1 == c_2 && c_2 == c_3 && c_3 == d_1 && d_1 == d_2;
        }
    
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            int ans = 0;
            for(int i = 0; i <= m - 3; i++){
                for(int j = 0; j <= n - 3; j++){
                    cout << i << " " << j << endl;
                    if(check(grid, i, j)) ans++;
                }
            }
    
            return ans;
        }
    };