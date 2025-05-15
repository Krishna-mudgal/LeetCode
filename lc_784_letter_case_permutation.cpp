#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
public: 

    void helper(string s, int idx, unordered_set<string> &st, int &n){
        if(idx >= n) {
            st.insert(s);
            return;
        }

        st.insert(s);

        for(int i = idx; i < n; i++){
            if(!isdigit(s[i])){
                int fact;
                if(s[i] >= 97 && s[i] <= 122) fact = 32;
                else fact = -32;

                s[i] -= fact;
                helper(s, i + 1, st, n);
                s[i] += fact;
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        unordered_set<string> st;

        helper(s, 0, st, n);
        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};