#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) { // using map
        int n = s.size();
        stack<pair<char, int>> st;
        unordered_map<int, char> invalid;
        int open = 0, close = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') {
                st.push({s[i], i});
            }
            else if(s[i] == ')' && st.size() == 0) { // means these close brackets donot make pair so add them to invalid
                invalid[i] = s[i];
            }
            else if (s[i] == ')')  {
                st.pop();
            }
        }

        while(st.size() > 0) { // adding open brackets which donot make pairs   
            auto t = st.top();
            st.pop();
            invalid[t.second] = t.first;
        }
        
        string ans = "";

        for(int i = 0; i < n; i++){
            if(invalid.find(i) == invalid.end()) ans += s[i]; // adding only valid characters
        }

        return ans;

    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) { // using set
        int n = s.size();
        stack<pair<char, int>> st;
        unordered_set<int> invalid;
        int open = 0, close = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') {
                st.push({s[i], i});
            }
            else if(s[i] == ')' && st.size() == 0) { // means these close brackets donot make pair so add them to invalid
                invalid.insert(i);
            }
            else if (s[i] == ')')  {
                st.pop();
            }
        }

        while(st.size() > 0) { // adding open brackets which donot make pairs   
            auto t = st.top();
            st.pop();
            invalid.insert(t.second);
        }
        
        string ans = "";

        for(int i = 0; i < n; i++){
            if(invalid.find(i) == invalid.end()) ans += s[i]; // adding only valid characters
        }

        return ans;

    }
};