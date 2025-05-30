#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 1; i < n; i++){
            for(int j = 1; j < matrix[i].size(); j++){
                if(matrix[i][j] != matrix[i - 1][j - 1]) return false;
            }
        }

        return true;
    }
};