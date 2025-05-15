#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:
    
    void helper(map<int, vector<int>> &m, int i, vector<int> v, vector<vector<int> > &ans, int &n){
        if(m.find(i) == m.end()) return;
        if(m[i].empty()) {
            if(i == n - 1) v.push_back(i);
            ans.push_back(v);
            return;
        }

        v.push_back(i);
        vector<int> x = m[i];

        for(int j = 0; j < x.size(); j++){
            helper(m, x[j], v, ans, n);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int, vector<int>> m;

        bool flag = true;
        int last_empty = -1;
        for(int i = 0; i < n; i++){
            if(!graph[i].empty()) m[i] = graph[i];
            else {
                if(last_empty != -1) m.erase(last_empty);
                m[i] = graph[i];
                last_empty = i;
            }
        }

        vector<vector<int>> ans;
        helper(m, 0, {}, ans, n);

        return ans;
    }
};