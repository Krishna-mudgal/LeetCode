#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string add(string &s2, int &n){
        string ans = "";

        for(int i = 0; i < n; i++) ans += s2;

        return ans;
    }

    string decodeString(string s) {
        int n = s.size();

        stack<string> st1;
        stack<int> st2;

        string num = "", s1 = "";
        int i = 0;
        while(i < n){
            if(isdigit(s[i])){
                while(isdigit(s[i])){ // poora digit nikal lo
                    num += s[i];
                    i++;
                }
                st2.push(stoi(num));
                num = "";
            }   
            else if(s[i] == ']'){ 
                string temp = "";
                while(st1.size() > 0 && st1.top() != "["){ 
                    temp += st1.top();
                    st1.pop();
                }

                st1.pop();

                int x = st2.top();
                st2.pop();
                st1.push(add(temp, x));
                i++;
            }
            else {
                string t = "";
                t += s[i];
                st1.push(t);
                i++;
            }
        }
        
        string ans = "";

        while(st1.size() > 0){
            ans += st1.top();
            st1.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;

    }
};