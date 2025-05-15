#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n != m) return false;

        unordered_map<char, int> m1, m2;

        for(auto c : s1) m1[c]++;

        for(auto c : s2){
            m2[c]++;

            if(m1.find(c) == m1.end()) return false;
            else if(m2[c] > m1[c]) return false;
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) cnt++;
        }

        return cnt < 3;
    }
};