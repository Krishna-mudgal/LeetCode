#include <bits/stdc++.h>
using namespace std;

class Solution { // brute force
public:
    int minLength(string s) {
        string x = "";

        while(s.size() > 0){
            int n = s.size();
            x = "";
            bool flag = true;
            int i = 0;
            while(i < n){
                if(i + 1 < n && ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D'))){
                    i += 2;
                    flag = false;
                }
                else {
                    x += s[i];
                    i++;
                }
            }
            if(flag) break;
            s = x;
        }

        return x.size();

    }
};

class Solution {
public:
    int minLength(string s) { // approach - 2, optimized

        int n = s.size();
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(st.size() == 0) st.push(s[i]);
            else if((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D')) st.pop();
            else st.push(s[i]);
        }

        return st.size();
        
    }
};