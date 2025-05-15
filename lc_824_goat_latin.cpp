#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/goat-latin/description/

class Solution {
public:
    string toGoatLatin(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        string x = "a";
        while(i < n){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                ans += s[i];
                i++;
                while(i < n && s[i] != ' '){
                    ans += s[i];
                    i++;
                }
                i++;
            }
            else {
                char c = s[i];
                i++;
                while(i < n && s[i] != ' '){
                    ans += s[i];
                    i++;
                }
                i++;
                ans += c;
            }
            ans += "ma";
            ans += x;
            x += 'a';
            ans += ' ';
        }

        ans.pop_back();
        return ans;
    }
};