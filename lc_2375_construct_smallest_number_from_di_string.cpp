#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();

        stack<char> st;
        string ans = "";

        char x = '1';
        int i = 0;
        while(i < n){
            if(i == n - 1 && pattern[i] == 'D'){
                st.push(x++);
            }
            if(pattern[i] == 'I'){
                st.push(x);
                x++;
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
                i++;
            }
            else {
                st.push(x);
                x++;
                i++;
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        if(pattern[n - 1] == 'I') ans += x;

        return ans;
    }
};