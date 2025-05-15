#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindrome/description/


class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> m; // freq map

        for(int i = 0; i < n; i++) m[s[i]]++;

        bool odd_size_taken = false;

        if(m.size() == 1) return m[s[0]];

        for(auto p : m) {
            if(p.second % 2 == 0) ans += p.second;
            else {// odd size m apn even wala part to la hi skte h
                ans += p.second - 1;
                odd_size_taken = true;
            }
        }

        if(odd_size_taken) ans += 1; // agr kbhi bhi odd liya tha to apn ne uska even part liya h to +1 krke apne usko pura odd krdege sirf ek char ko

        return ans;

    }
};