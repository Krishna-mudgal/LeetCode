#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-segments-in-a-string/description/

class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        if(n == 0) return 0;

        int ans = 0;
        int i = 0;
        int cnt = 0; // for ' '
        int cnt_2 = 0; // for character other than ' '
        while(i < n){
            if(s[i] == ' '){
                while(i < n && s[i + 1] == ' '){
                    i++;
                    cnt++;
                }
                i++;
                cnt++;
                if(cnt_2 > 0) ans++; // agr space milne se phle ek bhi character phle mila ho to hi bdana ans 
            }
            else {
                i++;
                cnt_2++;
            }
        }

        if(cnt == 0) return 1; // means so space
        else if(cnt == n) return 0; // means only space

        if(s[n - 1] == ' ') return ans; // means ends with ' '
        else return ans + 1; // means ends with a word

    }
};