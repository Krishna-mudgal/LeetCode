#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02

class Solution {
public:
    int isPrefixOfWord(string sentence, string word) {
        int n = sentence.size(), m = word.size();

        int ans = -1;
        int i = 0;
        int j = 0;
        int idx = 1;
        while(i < n){
            j = 0;
            while(i < n && j < m && sentence[i] == word[j]){
                i++;
                j++;
            }
            if(j == m && ans == -1) ans = idx;

            while(i < n && sentence[i] != ' ') i++;
            i++;
            idx++;
        }

        return ans;
    }
};