#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix, suffix(n);
        int pre = 0;
        for(int i = 0; i < n; i++) {
            pre += nums[i];
            prefix.push_back(pre);
        }
        int suff = 0;
        for(int i = n - 1; i >= 0; i--) {
            suff += nums[i];
            suffix[i] = suff;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            int left_sum = prefix[i];
            int right_sum = suffix[i + 1];

            if((left_sum + right_sum) % 2 == 0) ans++;
        }

        return ans;
    }
};