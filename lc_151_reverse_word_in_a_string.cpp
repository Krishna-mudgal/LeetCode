#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution { // approach - 1
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> v;
        int i = 0;

        string x = "";
        while(i < n){
            if(s[i] == ' '){
                if(x != "") v.push_back(x);
                x = "";
            }
            else x += s[i];

            i++;
        }

        if(x != "") v.push_back(x); // pushing last word;

        reverse(v.begin(), v.end());

        x = "";
        for(int i = 0; i < v.size(); i++){
            x += v[i];
            if(i < v.size() - 1) x += " ";
        }

        return x;
    }
};

class Solution { // approach - 2
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;

        string x = "";
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ' '){
                reverse(x.begin(), x.end());
                if(x != "") ans += (x + " ");
                x = "";
            }
            else x += s[i];
        }

        if(x != "") {
            reverse(x.begin(), x.end());
            ans += x;
        }

        if(ans[ans.size() - 1] == ' ') ans.pop_back();
        
        return ans;
    }
};