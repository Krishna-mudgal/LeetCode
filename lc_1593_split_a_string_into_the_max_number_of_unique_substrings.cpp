#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/?envType=daily-question&envId=2024-10-21

class Solution {
public:

    void helper(string &s, unordered_set<string> &st, int idx, int &ans){
        if(idx >= s.size()) return;

        string x = "";
        for(int i = idx; i < s.size(); i++){ // ek particular index se saare substring ke liye helper call krdo recursively
            x += s[i];
            if(st.find(x) == st.end()){
                st.insert(x);
                int a = st.size();
                ans = max(ans, a);
                helper(s, st, i + 1, ans);
                st.erase(x);
            }
        }

    }

    int maxUniqueSplit(string s) {
        int n = s.size();
        
        unordered_set<string> st;
        int ans = 0;
        helper(s, st, 0, ans);

        return ans;
    }
};