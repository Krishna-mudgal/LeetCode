#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

class Solution { // T.C. = O(n*n*3*3) = O(n^2)
    public:
        vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<int>> ans(n - 2, vector<int> (n - 2, -1));
    
            int i = 0, j = 0;
            while(i < n - 2){ // T.c = O(n)
                j = 0;
                while(j < n - 2) { // T.C = O(n)
                    int maxi = INT_MIN;
                    for(int k = i; k < i + 3; k++){ // T.C. = O(3)
                        for(int l = j; l < j + 3; l++){ // T.C. = O(3)
                            maxi = max(maxi, grid[k][l]);
                        }
                    }
    
                    ans[i][j] = maxi;
                    j++;
                }
                i++;
            }
    
            return ans;
        }
    };