#include <bits/stdc++.h>
using namespace std;

//  https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        if(s > n*m || s < n*m) return {};
        if(m == 1) return {original};
        
        vector<vector<int>> ans(m, vector<int>(n));

        int a = 0, b = 0;
        for(int i = 0; i < s; i++){
            if(a == n){
                a = 0;
                b++;
            }
            if(b >= m) return ans;
            ans[b][a++] = original[i];
        }

        return ans;

    }
};