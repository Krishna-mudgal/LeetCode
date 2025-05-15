#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string x = "";
        for(char c : firstWord) x += (c - 'a') + '0';
        int a = stoi(x);

        x = "";
        for(char c : secondWord) x += (c - 'a') + '0';
        a += stoi(x);

        string y = "";
        for(char c : targetWord) y += (c - 'a') + '0';
        return a == stoi(y);
    }
};