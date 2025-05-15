#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans;
        int i = 0, j = 0;
        int idx = -1;
        int last_idx = -1;
        while(j < n){
            if(s[j] == c){
                last_idx = idx;
                idx = j;
                while(i <= j){
                    if(last_idx != -1) ans.push_back(min(abs(i - last_idx), abs(i - j)));
                    else ans.push_back(abs(i - j));
                    i++;
                }
            }
            j++;
        }

        if(ans.size() < s.size()){
            int x = idx + 1;
            while(ans.size() != s.size()){
                ans.push_back(abs(x - idx));
                x++;
            }
        }

        return ans;
    }
};