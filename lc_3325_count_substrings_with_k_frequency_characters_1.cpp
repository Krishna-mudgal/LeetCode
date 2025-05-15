#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<char, int> m;
            for(int j = i; j < n; j++){
                m[s[j]]++;
                if(m[s[j]] == k) {
                    ans += n - j;
                    break;
                }
            }
        }

        return ans;
    }
};