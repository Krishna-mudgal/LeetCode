#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    /*

        1. mujhe aesa subsequence dekhna hai jiska lower half part ko agr me reverse agr do upper half part ke equal ho
        2. what if me do string lu ek as it is and other one reverse of it or dono ka longest common subsequence nikal lu.
        3. to jo bhi longest sub-sequence ayga whi h ans.

    */
    vector<vector<int>> dp;
    int helper(string &s1, string &s2, int i, int j) {
        if(i == s1.size() || j == s2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + helper(s1, s2, i + 1, j + 1);
        } else {
            return dp[i][j] = max(helper(s1, s2, i + 1, j), helper(s1, s2, i, j + 1));
        }
    }

    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int> (s.size(), -1));
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return helper(s, s2, 0, 0);
    }
};


class Solution { // another approach
public:

    vector<vector<int>> dp;
    int helper(string &s, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) return dp[i][j] = 1;

        if(s[i] == s[j]) return dp[i][j] = 2 + helper(s, i + 1, j - 1);
        else return dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
    }

    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return helper(s, 0, s.size() - 1);
    }
};