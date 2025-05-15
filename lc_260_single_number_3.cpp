#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-number-iii/

class Solution { // time : O(n), space = O(n)
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;

        for(int i : nums){
            if(s.find(i) != s.end()) s.erase(i);
            else s.insert(i);
        }

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};