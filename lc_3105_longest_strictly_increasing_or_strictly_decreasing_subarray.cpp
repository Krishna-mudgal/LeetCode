#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;

        for(int i = 0; i < n; i++){
            int c = 1; // denoting the ith index element subaray
            for(int j = i; j < n - 1; j++){
                if(nums[j] < nums[j + 1]) c++;
                else break;
            }
            a = max(a, c);
        }

        for(int i = 0; i < n; i++){
            int c = 1; // denoting the ith index element subaray
            for(int j = i; j < n - 1; j++){
                if(nums[j] > nums[j + 1]) c++;
                else break;
            }
            b = max(b, c);
        }

        return max(a, b);
    }
};