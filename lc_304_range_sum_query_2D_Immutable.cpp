#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

class NumMatrix {
public:
    vector<vector<int> > v;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        v.clear();
        v.resize(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j > 0) v[i][j] = v[i][j - 1] + matrix[i][j];
                else v[i][j] = matrix[i][j];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 > 0) ans += (v[i][col2] - v[i][col1 - 1]);
            else ans += v[i][col2];
        }

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */