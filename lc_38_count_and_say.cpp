#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18

class Solution { // T.C. = O(2^n)
    public:
        string countAndSay(int n) {
           if(n == 1)  return "1";
           string s1 = countAndSay(n - 1);
           string s2 = "" ;
           int i = 0;
           int x = 1;
           while(i < s1.size()){
                if(i + 1 < s1.size() && s1[i] == s1[i + 1]){
                    x++;
                    i++;
                }
                else {
                    s2 += to_string(x);
                    s2 += s1[i];
                    i++;
                    x = 1;
                }
           }
    
           return s2;
        }
    };