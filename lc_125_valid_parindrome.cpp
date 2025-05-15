#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) { // better than previous solution
        int n = s.size();
        if(n == 0 || n == 1) return true;

        int i = 0, j = n - 1;

        while(i <= j){
            if(!isalnum(s[i])){
                i++;
                continue;
            } 
            else if(!isalnum(s[j])){
                j--;
                continue;
            }
            else {
                int x = (int)s[i], y = (int)s[j];
                if(isupper(s[i])){
                    s[i] = (char)(s[i] + 32);
                }
                if(isupper(s[j])){
                    s[j] = (char)(s[j] + 32);
                }

                if(s[i] != s[j]) return false;

                i++;
                j--;
            }
        }

        return true;
    }
};