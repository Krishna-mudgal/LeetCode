#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2024-11-21

class Solution {
public:

    void helper(vector<vector<int>>& v, int &i, int &j, int &m , int &n, int &ans){        
        // downwards
        for(int k = i + 1; k < m; k++){
            if(v[k][j] == 1 || v[k][j] == 0) break;
            if(v[k][j] == -1){
                ans--;
                v[k][j] = 2; // marking guarded cells
            }
        }

        // upwards
        for(int k = i - 1; k >= 0; k--){
            if(v[k][j] == 1 || v[k][j] == 0) break;
            if(v[k][j] == -1){
                ans--;
                v[k][j] = 2; // marking guarded cells
            }
        }

        // rightwards
        for(int k = j + 1; k < n; k++){
            if(v[i][k] == 1 || v[i][k] == 0) break;
            if(v[i][k] == -1){
                ans--;
                v[i][k] = 2; // marking guarded cells
            }
        }

        // leftwards
        for(int k = j - 1; k >= 0; k--){
            if(v[i][k] == 1 || v[i][k] == 0) break;
            if(v[i][k] == -1){
                ans--;
                v[i][k] = 2; // marking guarded cells
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int> >v(m, vector<int> (n, -1));

        // 0 -> guard, 1 -> wall, -1 -> ungaurded cell, 2 -> gaurded cell
        
        int ans = m*n;
        for(int i = 0; i < walls.size(); i++){
            ans--;
            v[walls[i][0]][walls[i][1]] = 1;
        }

        for(int i = 0; i < guards.size(); i++){
            ans--;
            v[guards[i][0]][guards[i][1]] = 0;
        }

        for(int i = 0; i < guards.size(); i++){
            helper(v, guards[i][0], guards[i][1], m, n, ans);
        }

        return ans;

    }
};  