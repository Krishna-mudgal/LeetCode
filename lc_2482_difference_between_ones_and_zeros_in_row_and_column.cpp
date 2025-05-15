#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, int> m1; // for onerow
        unordered_map<int, int> m2; // for onecol

        for(int i = 0; i < n; i++){
            int noo = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) noo++;
            }
            m1[i] = noo;
        }

        for(int i = 0; i < m; i++){
            int noo = 0;
            for(int j = 0; j < n; j++){
                if(grid[j][i] == 1) noo++;
            }
            m2[i] = noo;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int oner = m1[i], onec = m2[j];
                int zeror = n - oner, zeroc = m - onec;

                grid[i][j] = (oner + onec - zeror - zeroc);
            }
        }

        return grid;
    }
};