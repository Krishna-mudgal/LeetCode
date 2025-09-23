#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-only-letters/description/

class Solution {
public:

    bool isLetter(char &c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(!isLetter(s[i])) i++;
            else if(!isLetter(s[j])) j--;
            else swap(s[i++], s[j--]);
        }

        return s;
    }
};