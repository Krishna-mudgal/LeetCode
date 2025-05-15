#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/?envType=daily-question&envId=2024-12-04

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(m > n) return false;
        int i = 0, j = 0;

        while(i < n){
            if(str1[i] != str2[j]) {
                int x = str1[i];
                if(x == 122) x = 97;
                else x++;
                str1[i] = (char)(x);
            }
            if(str1[i] == str2[j]) j++;

            i++;
        }

        i = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(str1[i] == str2[j]) j++;

            if(j == m) break;
        }

        if(j == m) return true;
        else return false;
    }
};