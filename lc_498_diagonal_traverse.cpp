#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/diagonal-traverse/description/?envType=daily-question&envId=2025-08-25

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++ ) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i = 0; i <= (m + n - 2); i++) {
            if(i % 2 == 0) {
                int j = 0, k = mp[i].size() - 1;
                while(j < k) {
                    swap(mp[i][k], mp[i][j]);
                    j++;
                    k--;
                }
            }

            for(int &x : mp[i]) ans.push_back(x);
        }


        return ans;
    }
};