#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/queries-on-a-permutation-with-key/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> v;
        for(int i = 1; i <= m; i++) v.push_back(i);

        vector<int> ans;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            int q = queries[i];
            int idx = -1;
            for(int j = 0; j < m; j++){
                if(v[j] == q) {
                    idx = j;
                    break;
                }
            }
            ans.push_back(idx);
            temp.resize(0);
            temp.push_back(v[idx]);
            for(int j = 0; j < m; j++){
                if(j != idx) temp.push_back(v[j]);
            }
            v = temp;
        }

        return ans;
    }
};