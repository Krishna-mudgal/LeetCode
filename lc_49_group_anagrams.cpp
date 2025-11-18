#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto s : strs) {
            string s1 = s;
            sort(s1.begin(), s1.end());
            mp[s1].push_back(s);
        }

        for(auto p : mp) ans.push_back(p.second);
        return ans;
    }
};