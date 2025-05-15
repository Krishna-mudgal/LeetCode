#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int> m;

        int ans = 0;
        for(int i = 0; i < n; i++){
            m[s[i]]++;
        }

        for(auto p : m){
            if(p.second % 2 != 0) ans += 1;
            else ans += 2;
        }

        return ans;
    }
};