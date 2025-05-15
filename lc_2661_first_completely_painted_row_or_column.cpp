#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m2 = mat[0].size();

        unordered_map<int, pair<int, int>> m; // {num, {row_no, col_no}}
        unordered_map<int, vector<int>> c, r;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m2; j++){
                m[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); i++){
            int num = arr[i];
            r[m[num].first].push_back(num);
            if(r[m[num].first].size() == m2) return i;

            c[m[num].second].push_back(num);
            if(c[m[num].second].size() == n) return i;
        }

        return -1;
    }
};