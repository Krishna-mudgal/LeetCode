#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=daily-question&envId=2025-09-13

class Solution {
public:
    int maxFreqSum(string s) { // T.C. = O(n), S.C. = O(n)
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto c : s) mp[c]++;

        int vowel_freq = 0;
        int conso_freq = 0;

        for(auto p : mp){
            if(p.first == 'a' || p.first == 'e' || p.first == 'i' || p.first == 'o' || p.first == 'u') {
                vowel_freq = max(vowel_freq, p.second);
            } else conso_freq = max(conso_freq, p.second);
        }

        return conso_freq + vowel_freq;
    }
};


class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        sort(s.begin(), s.end());

        int vowel_freq = 0;
        int conso_freq = 0;

        int i = 0, j = 0;
        while(j < n) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                int cnt = 0;
                j = i;
                while(j < n && s[j] == s[i]) {
                    j++;
                    cnt++;
                }
                vowel_freq = max(vowel_freq, cnt);
                i = j;
            } else {
                int cnt = 0;
                j = i;
                while(j < n && s[j] == s[i]) {
                    j++;
                    cnt++;
                }
                conso_freq = max(conso_freq, cnt);
                i = j;
            }
        }

        return vowel_freq + conso_freq; 
    }
};