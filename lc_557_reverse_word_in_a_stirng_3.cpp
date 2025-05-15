#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        int i = 0, j = 0;

        while(j < n){
            if(s[j] != ' ') j++;
            else {
                reverse(s.begin() + i, s.begin() + j);
                j++;
                i = j;
            }
        }

        reverse(s.begin() + i, s.end()); // to reverse last word

        return s;

    }
};