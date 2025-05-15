#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int v = 0;
        int n = s.size();
        int i = 0, j = 0;

        while(j < k){
            if(isVowel(s[j])) v++;
            j++;
        }
        ans = max(ans, v);

        while(j < n){
            if(isVowel(s[i])) v--;
            i++;
            if(isVowel(s[j])) v++;
            j++;

            ans = max(ans, v);
        }

        return ans;
    }
private :
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};