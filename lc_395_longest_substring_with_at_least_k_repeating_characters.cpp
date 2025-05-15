#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> m;
            for(int j = i; j < n; j++){
                m[s[j]]++;
                bool flag = true;
                for(auto p : m){
                    if(p.second < k) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};