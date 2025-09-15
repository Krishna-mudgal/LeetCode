#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) { // T.C. = O(n)
        int n = text.size();
        unordered_map<char, int> mp;
        for(auto c : brokenLetters) mp[c]++;

        int ans = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(mp.find(text[i]) != mp.end()) flag = false;
            else if(text[i] == ' ') {
                if(flag) ans++;
                flag = true;
            }
        }

        if(flag) ans++;

        return ans;
    }
};