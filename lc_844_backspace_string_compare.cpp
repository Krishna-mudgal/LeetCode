#include <bits/stdc++.h>
using namespace std;

https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;

        int i = 0, j = 0;

        while(i < s.size()){ // process s1
            if(s[i] == '#' && s1.size() > 0) s1.pop();
            else if(s[i] != '#') s1.push(s[i]);
            i++;
        }

        while(j < t.size()){ // process s2
            if(t[j] == '#' && s2.size() > 0) s2.pop();
            else if(t[j] != '#') s2.push(t[j]);
            j++;
        }
        
        if(s1.size() != s2.size()) return false;

        while(s1.size() > 0){
            if(s1.top() != s2.top()) return false;

            s1.pop();
            s2.pop();
        }

        return true;

    }
};