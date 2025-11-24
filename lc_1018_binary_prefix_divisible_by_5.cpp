#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=daily-question&envId=2025-11-24

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        int num = 0;
        for(int i : nums) {
            if(i == 1) num = num*2 + 1;
            else num *= 2;

            (num % 5 == 0)  ? ans.push_back(true) : ans.push_back(false);

            num %= 5;
        }

        return ans;
    }
};