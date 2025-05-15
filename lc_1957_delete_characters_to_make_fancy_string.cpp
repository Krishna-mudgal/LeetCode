#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();

        int i = 0, j = 0;

        int x = 0;
        string ans = "";
        while(j < n){

            if(s[j] == s[i]){
                x++;
                if(x < 3) ans += s[j];
                j++;
            }
            else{
                i = j;
                x = 0;
            }
            
        }

        return ans;

    }
};