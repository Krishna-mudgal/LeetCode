#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for(int &i : nums) st.insert(i);
        int ans = 0;
        while(st.find(original) != st.end()) {
            original *= 2;
        }

        return original;
    }
};