#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

class Solution {
    public:
        vector<int> findArray(vector<int>& pref) {
            int n = pref.size();
            vector<int> ans;
            int x = pref[0];
            ans.push_back(x);
            for(int i = 1; i < n; i++){
                x = x ^ pref[i];
                ans.push_back(x);
                x = pref[i];
            }
    
            return ans;
        }
    };