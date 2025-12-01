#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &i : nums) sum += i;

        return sum % k;
    }
};