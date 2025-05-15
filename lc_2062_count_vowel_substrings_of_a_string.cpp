#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/

class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int countVowelSubstrings(string word) { // T.c = O(n^2)
        int n = word.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> m;

            if(!isVowel(word[i])) continue; // if word[i] is consonant then break

            for(int j = i; j < n; j++){

                if(!isVowel(word[j])) break; // if there is any consonant then break

                m[word[j]]++;
                if(m.size() == 5) ans++;
            }
        }

        return ans;
    }
};