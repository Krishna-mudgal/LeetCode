#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-pattern/description/


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        int j = 0;
        int t = pattern.size();
        if(n == 1 && t == 1){
            if(n == t) return true;
            else return false; 
        }
        if(n == t) return false;
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        string wrd = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(m1.find(pattern[j]) != m1.end()){
                    if(m1[pattern[j]] != wrd) return false;
                    j++;
                    wrd = "";
                }
                else if(m2.find(wrd) != m2.end()){
                    if(m2[wrd] != pattern[j]) return false;
                    wrd = "";
                }
                else{
                    m1[pattern[j]] = wrd;
                    m2[wrd] = pattern[j];
                    j++;
                    wrd = "";
                }
            }
            else wrd += s[i];
        }

        if(m1.find(pattern[j]) != m1.end()){
            if(m1[pattern[j]] != wrd) return false;
        }
        else if(m2.find(wrd) != m2.end() && m2[wrd] != pattern[j]) return false;
        else{
            m1[pattern[j]] = wrd;
            m2[wrd] = pattern[j];
        }

        if(j != t - 1) return false;
        return true;
    }
};