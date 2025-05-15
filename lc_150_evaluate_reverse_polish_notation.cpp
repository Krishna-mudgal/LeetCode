#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> st;

        for(int i = 0; i < n; i++){
            if(tokens[i] == "+"){
                int a = st.top();
                st.pop();
                int b;
                if(!st.empty()){
                    b = st.top();
                    st.pop();
                }
                else b = 0;

                st.push(b + a);
            }
            else if(tokens[i] == "-"){
                int a = st.top();
                st.pop();
                int b;
                if(!st.empty()){
                    b = st.top();
                    st.pop();
                }
                else b = 0;

                st.push(b - a);
            }
            else if(tokens[i] == "*"){
                int a = st.top();
                st.pop();
                int b;
                if(!st.empty()){
                    b = st.top();
                    st.pop();
                }
                else b = 0;

                st.push(b * a);
            }
            else if(tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b;
                if(!st.empty()){
                    b = st.top();
                    st.pop();
                }
                else b = 0;

                st.push(b / a);
            }
            else st.push(stoi(tokens[i]));
        }

        return st.top();

    }
};