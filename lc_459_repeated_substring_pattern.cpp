#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/repeated-substring-pattern/description/

class Solution {
public:

    bool check(int i, int times, string &s){
        int n = s.size();
        string x = "";
        for(int j = 0; j < i; j++){
            x += s[j];
        }
        
        string repeat = "";
        for(int j = 0; j < times; j++) repeat += x;

        return repeat == s;
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                bool f = check(i, n/i, s);
                if(f) return f;
            }
        }

        return false;
    }
};