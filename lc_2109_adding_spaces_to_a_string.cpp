#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/adding-spaces-to-a-string/?envType=daily-question&envId=2024-12-03

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();

        string ans = "";
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(idx < spaces.size() && i == spaces[idx]){
                ans += " ";
                idx++;
            }
            ans += s[i];
        }

        return ans;
    }
};