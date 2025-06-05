#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05

class Solution { // T.c. = O(n + 26*m) = O(n + m)
public:

    void helper(char c1, unordered_map<char, vector<char>> &mp, unordered_set<char> &seen, char &c2){
        if((seen.find(c1) != seen.end()) || (mp.find(c1) == mp.end())) return;

        seen.insert(c1);
        for(auto c : mp[c1]) {
            c2 = min(c2, c);
            helper(c, mp, seen, c2);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();

        unordered_map<char, vector<char>> mp;

        for(int i = 0; i < n; i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }

        string ans = "";
        unordered_set<char> seen;
        for(int i = 0; i < m; i++){
            seen.clear();

            char c = 'z';
            helper(baseStr[i], mp, seen, c);

            ans += min(c, baseStr[i]);
        }

        return ans;
    }
};