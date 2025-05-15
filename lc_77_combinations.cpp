#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combinations/description/

class Solution {
public:

    void find(int i, int &n, int k, vector<int> &v, vector<vector<int> > &ans){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }

        for(int j = i; j <= n; j++){
            v.push_back(j);
            find(j + 1, n, k, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> v;

        find(1, n, k, v, ans);

        return ans;

    }
};