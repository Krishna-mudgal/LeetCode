#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/to-lower-case/description/

class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] >= 65 && s[i] <= 90) ans += char(s[i] + 32);
            else ans += s[i];
        }

        return ans;
    }
};