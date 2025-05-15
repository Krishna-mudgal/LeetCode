#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

class Solution { // T.C.= O(n)
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        int last = groups[0];
        for(int i = 1; i < n; i++){
            if(groups[i] != last){
                ans.push_back(words[i]);
                last = groups[i];
            }
        }

        return ans;
    }
};