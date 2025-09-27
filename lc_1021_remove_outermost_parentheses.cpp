#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        stack<char> st;
        string ans = "";
        int i = 0;
        while(i < n) {
            if(s[i] == '(') {
                if(!st.empty()) ans += '(';
                st.push('('); 
            } else {
                if(st.size() > 1) {
                    st.pop();
                    ans += ')';
                } else st.pop();
            }

            i++;
        }

        return ans;
    }
};