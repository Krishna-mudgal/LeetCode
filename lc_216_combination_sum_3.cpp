#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    
    void helper(int &k, int n, vector<vector<int> > &ans, vector<int> v, int idx){
        if(n < 0) return;

        if(v.size() == k && n == 0){
            ans.push_back(v);
            return;
        }

        for(int i = idx + 1; i <= 9; i++){
            if(i <= n) {
                v.push_back(i);
                helper(k, n - i, ans, v, i);
                v.pop_back();
            }
            else break;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(k, n, ans, v, 0);

        return ans;
    }
};