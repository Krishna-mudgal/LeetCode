#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-array-ii/description/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> v;

        for(int i : nums) {
            if(i % 2 == 0) v.push_back(0);
            else v.push_back(1);
        }
        int x = 0;
        vector<int> error; // this vector shows total number of violating indexes till ith index
        error.push_back(0);
        for(int i = 1; i < n; i++){
            if(v[i] == v[i - 1]) error.push_back(++x);
            else error.push_back(x);
        }

        vector<bool> ans;
        for(int i = 0; i < m; i++){
            int b = queries[i][1], a = queries[i][0];

            if(error[b] - error[a] == 0) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};