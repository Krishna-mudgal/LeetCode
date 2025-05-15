#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-image/description/

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            // transpose + swap
            int m = matrix.size(), n = matrix[0].size();
    
            for(int i = 0; i < m; i++){
                for(int j = 0; j <= i; j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
    
            // for(auto v : matrix){
            //     for(auto i : v) cout << i << " ";
            //     cout << endl;
            // }
    
            for(int i = 0; i < m; i++){
                int j = 0, k = n - 1;
                while(j < k){
                    swap(matrix[i][j], matrix[i][k]);
                    j++;
                    k--;
                }
            }
    
        }
    };