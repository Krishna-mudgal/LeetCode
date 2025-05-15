#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shifting-letters/description/

class Solution {
    public:
        string shiftingLetters(string s, vector<int>& shifts) {
            int n = s.size();
    
            for(int i = n - 2; i >= 0; i--){
                shifts[i] += shifts[i + 1];
                shifts[i] %= 26;
            }
    
            for(int i = 0; i < n; i++){
                int shift = shifts[i];
                shift = shift % 26;
                if(s[i] + shift > 122){
                    shift = s[i] + shift - 122;
                    s[i] = 'a' + shift - 1;
                }
                else s[i] += shift;
            }
    
            return s;
        }
    };