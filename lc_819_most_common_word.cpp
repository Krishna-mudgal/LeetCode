#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-common-word/description/

class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        int n = p.size();

        unordered_map<string, int> m;
        unordered_set<string>st;

        for(string s : banned) st.insert(s);

        string x = "";
        for(int i = 0; i < n; i++){
            if(p[i] != ' ' && p[i] != '.' && p[i] != '?' && p[i] != '!' && p[i] != ',' && (int)p[i] != 39 && p[i] != ';') x += tolower(p[i]);
            else {
                if(x != "") m[x]++;
                x = "";
            }
        }  
        if(x != "") m[x]++;

        int mx_cnt = -1;
        x = "";
        for(auto p : m){
            if(st.find(p.first) == st.end()){
                if(mx_cnt < p.second){
                    mx_cnt = p.second;
                    x = p.first;
                }
            }
        }

        return x;

    }
};