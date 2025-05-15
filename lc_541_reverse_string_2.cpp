#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-string-ii/description/

class Solution {
public:
    
    void reverse(string &s, int lo, int hi){
        if(lo >= hi) return;

        while(lo < hi){
            swap(s[lo], s[hi]);
            lo++;
            hi--;
        }

    }

    string reverseStr(string s, int k) {
        int n = s.size();

        if(n <= k){
            reverse(s, 0, n - 1);
            return s;
        }

        int i = 0;
        while(i < n){
            if(i + k - 1 < n) reverse(s, i, i + k - 1);
            else reverse(s, i, n - 1);

            i = i + 2*k;
        }

        return s;

    }
};