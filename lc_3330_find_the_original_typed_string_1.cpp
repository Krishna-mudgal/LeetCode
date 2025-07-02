#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        string s = "";
        vector<pair<int, int>> v;
        int ans = 1;
        int i = 0, j = 0;
        while(j < n) {
            j = i + 1;
            int x = 0;
            while(j < n && word[j] == word[i]) {
                j++;
                x++;
            }

            v.push_back({i, x});
            i = j;
        }

        for(auto p : v) {
            ans += p.second;
        }

        return ans;
    }
};