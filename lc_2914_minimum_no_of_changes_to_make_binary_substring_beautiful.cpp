#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/?envType=daily-question&envId=2024-11-05

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();

        int ans = 0;
        int i = 0, cnt = 0;
        char c = s[0]; // used to store current comparing character
        while(i < n){
            if(s[i] == c) {
                cnt++;
                i++;
            }
            else{
                if(cnt % 2 == 0){ // means ki ek even length ki substring to bn hi gya h of 0's or 1's to ab jo alg aya h usse dusri string banane ka try kro
                    c = s[i]; 
                    cnt = 1;
                    i++;
                }
                else{
                    cnt++;
                    ans++; // change krdiya
                    i++;
                }
            }
        }

        return ans;

    }
};