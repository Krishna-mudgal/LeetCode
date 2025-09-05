#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/buddy-strings/description/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size()) return false;
        unordered_map<char, int> mp1, mp2;
        bool flag = false;
        for(auto &c : goal) {
            mp1[c]++;

            if(mp1[c] > 1) flag = true;
        }

        int notEqualPosition = 0;
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(mp1.find(c) == mp1.end()) return false;

            mp2[c]++;

            if(mp2[c] > mp1[c]) return false;

            if(s[i] != goal[i]) notEqualPosition++;

            if(notEqualPosition > 2) return false;
        }

        if(s == goal) return flag;

        return true;
    }
};