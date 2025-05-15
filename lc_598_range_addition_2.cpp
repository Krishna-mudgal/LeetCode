#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int s = ops.size();
         
        if(s == 0) return m*n;

        int m_min = ops[0][0], n_min = ops[0][1];

        for(int i = 1; i < s; i++){
            m_min = min(m_min, ops[i][0]);
            n_min = min(n_min, ops[i][1]);
        }

        return m_min * n_min;

    }
};