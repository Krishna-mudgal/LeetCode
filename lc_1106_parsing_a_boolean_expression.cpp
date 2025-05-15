#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20

class Solution {
public:
    
    char parse_and(string t){
        
        for(char c : t){
            if(c == 'f') return 'f';
        }

        return 't';
    }

    char parse_or(string t){

        for(char c : t){
            if(c == 't') return 't';
        }

        return 'f';
    }

    char parse_not(string t){
        return (t == "t") ? 'f' : 't';
    }
    
    bool parseBoolExpr(string s) {
        int n = s.size() ;

        stack<char> st;
        
        int i = 0;
        while(i < n){
            char ch = s[i];

            if(ch == ')'){
                string t = "";
                while(st.top() != '('){
                    if(st.top() != ',') t += st.top();
                    st.pop();
                }
                st.pop(); // removing '('

                char op = st.top();
                st.pop();

                if(op == '!') st.push(parse_not(t));
                if(op == '&') st.push(parse_and(t));
                if(op == '|') st.push(parse_or(t));

                i++;
            }
            else {
                st.push(ch);
                i++;
            }
        }

        return (st.top() == 't') ? true : false;

    }
};