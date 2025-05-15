#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/build-array-from-permutation/?envType=daily-question&envId=2025-05-06

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> arr(n);
            for(int i = 0; i < n; i++){
                arr[i] = nums[nums[i]];
            }
    
            return arr;
        }
    };