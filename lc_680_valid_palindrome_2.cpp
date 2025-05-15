#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:

    bool check(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        bool flag = true;

        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else if(flag) {
                if(check(s, l, r - 1)) return true; // check if by deleting character pointed by r, str becomes palindrome or not if yes then return true else do l++
                else l++;
                flag = !flag;
            }
            else return false;
        }

        return true;
        
    }
};