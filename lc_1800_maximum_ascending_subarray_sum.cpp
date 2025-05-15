#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int i = 1;
        int sum = nums[0];
        while(i < n){
            if(nums[i] > nums[i - 1]){
                sum += nums[i];
                i++;
            }
            else {
                ans = max(ans, sum);
                sum = nums[i];
                i++;
            }
        }

        ans = max(ans, sum);

        return ans;
    }
};