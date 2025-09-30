#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        for(int i = 0; i < n - 1; i++) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }

        nums.pop_back();

        return triangularSum(nums);
    }
};