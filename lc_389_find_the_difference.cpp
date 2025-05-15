#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-difference/description/


class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < n; i++){
            if(s[i] != t[i]) return t[i];
        }

        return t[n];
    }
};

// another approach (with improved time and complexity)

class Solution {
public:
    char findTheDifference(string s, string t) { // better approach
        int n = s.size();
        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++) freq[s[i] - 'a']++;

        for(int i = 0; i <= n; i++){
            if(freq[t[i] - 'a'] == 0) return t[i];

            freq[t[i] - 'a']--;
        }

        return '#';

    }
};