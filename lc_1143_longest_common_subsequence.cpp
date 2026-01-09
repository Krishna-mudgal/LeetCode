#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:

    vector<vector<int>> dp;
    int helper(string &s1, string &s2, int i, int j) {
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) { // if equal then increase both i and j by 1
            return dp[i][j] = 1 + helper(s1, s2, i + 1, j + 1);
        } else { // if not equal then skip one character from both one by one and choose that one which gives max ans
            return dp[i][j] = max(helper(s1, s2, i + 1, j), helper(s1, s2, i, j + 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int> (text2.size(), -1));
        return helper(text1, text2, 0, 0);
    }
};