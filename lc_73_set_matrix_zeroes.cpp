#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/description/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();

        set<pair<int, int> >s;

        for(int i  = 0; i < n; i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0 && (s.find({i, j}) == s.end())){
                    for(int k = 0; k < matrix[i].size(); k++){// travelling row wise
                        // agr phle se zero h to usko mt daalo kyu ki uski row aur coloum ko bhi zero krna hai
                        if(matrix[i][k] != 0){ 
                            matrix[i][k] = 0;
                            s.insert({i, k});
                        }
                    }
                    for(int k = 0; k < n; k++){ // travelling col wise
                        // agr phle se zero h to usko mt daalo kyu ki uski row aur coloum ko bhi zero krna hai 
                        if(matrix[k][j] != 0){ 
                            matrix[k][j] = 0;
                            s.insert({k, j});
                        }
                    }
                }
            }
        }

    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<pair<int, int>> v;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) v.push_back({i, j});
            }
        }

        for(auto p : v){
            int row = p.first, col = p.second;
            for(int i = 0; i < n; i++) matrix[row][i] = 0;
            for(int i = 0; i < m; i++) matrix[i][col] = 0;
        }

    }
};