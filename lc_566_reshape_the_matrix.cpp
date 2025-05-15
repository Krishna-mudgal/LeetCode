#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reshape-the-matrix/description/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) { 
        int m = mat.size(), n = mat[0].size();
        if(r * c != m * n || (r == m && c == n)) return mat;

        vector<vector<int> > ans(r, vector<int> (c));
        int a = 0, b = 0; // a -> row, b = coloum

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[a][b++] = mat[i][j];
                
                if(b == c){
                    a++;
                    b = 0;
                }
            }
        }

        return ans;

    }
};