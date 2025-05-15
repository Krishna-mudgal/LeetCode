#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/strong-password-checker-ii/description/

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
       int n = password.size() ;
       if(n < 8) return false;

        bool f1 = false;
        bool f2 = false;
        bool f3 = false;
        bool f4 = false;

        char last_c = '=';
        for(char c : password){
            if(c >= 'a' && c <= 'z') f1 = true;
            else if(c >= 'A' && c <= 'Z') f2 = true;
            else if(c >= '0' && c <= '9') f3 = true;
            else f4 = true;

            if(last_c != '=' && last_c == c) return false;

            last_c = c;
        }

        return (f1 && f2 && f3 && f4);

    }
};