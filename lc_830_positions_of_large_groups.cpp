#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/positions-of-large-groups/description/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();

        vector<vector<int>> ans;

        char c = s[0];
        int idx = 0;
        string x = "";
        for(int i = 0; i < n; i++){
            if(s[i] == c) x += s[i];
            else {
                c = s[i];
                if(x.size() >= 3) ans.push_back({idx, i - 1});
                idx = i;
                x = c;
            }
        }

        if(idx != n - 1 && s[idx] == s[n - 1] && n - idx >= 3) ans.push_back({idx, n - 1});

        return ans;
    }
};