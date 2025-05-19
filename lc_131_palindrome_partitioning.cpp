#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution { // T.c. = O(n * 2^n)
public:
    
    bool check(string y){
        int i = 0, j = y.size() - 1;
        while(i <= j){
            if(y[i] != y[j]) return false;

            i++;
            j--;
        }

        return true;
    }

    void helper(string &s, vector<vector<string>> &ans, int idx, vector<string> &v){
        if(idx >= s.size()){
            ans.push_back(v);
            return;
        }

        string x = "";

        for(int i = idx + 1; i <= s.size(); i++){
            x += s[i - 1];
            if(check(x)){
                v.push_back(x);
                helper(s, ans, i, v);
                v.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        helper(s, ans, 0, v);

        return ans;
    }
};