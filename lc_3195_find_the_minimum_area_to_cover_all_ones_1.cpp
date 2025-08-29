#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/?envType=daily-question&envId=2025-08-22

class Solution { // T.C. = O(m*n);
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int min_r = INT_MAX, min_c = INT_MAX;
        int max_r = INT_MIN, max_c = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    min_r = min(min_r, i);
                    min_c = min(min_c, j);

                    if(min_r != INT_MAX) max_r = max(max_r, i);
                    if(min_c != INT_MAX) max_c = max(max_c, j);
                }
            }
        }

        int l = 1;
        if(max_r != INT_MIN) l += max_r - min_r;
        
        int b = 1;
        if(max_c != INT_MIN) b += max_c - min_c;

        return l*b;
    }
};