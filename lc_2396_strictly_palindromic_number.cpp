#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/strictly-palindromic-number/description/

class Solution {
public:

    bool check(int n, int base){
        string s = "";
        
        while(n > 0){
            int x = n % base;

            s += (x + '0');
            n /= base;
        }

        int i = 0, j = s.size() - 1;

        while(i <= j){
            if(s[i] != s[j]) return false;
        }

        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i < n; i++) {
            if(!check(n, i)) return false;
        }

        return true;
    }
};