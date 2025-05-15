#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return false;

        unordered_map<int, int> m;

        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) != m.end()) return true;
            m[nums[i]]++;
        }

        return false;
    }
};