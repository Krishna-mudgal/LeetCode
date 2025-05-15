#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    bool isVowel(char a){
        return a == 'a' || a == 'A' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||  a == 'E' || a == 'I' || a == 'O' || a == 'U';
    }
    string reverseVowels(string s) {
        int n = s.size();

        int i = 0, j = n - 1;

        while(i <= j){

            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i]) && !isVowel(s[j])) j--;
            else if(!isVowel(s[i]) && isVowel(s[j])) i++;
            else{
                i++;
                j--;
            }
        }

        return s;

    }
};