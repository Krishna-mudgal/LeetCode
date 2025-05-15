#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<long long int> v(n);
        v[0] = nums[0];

        for(int i = 1; i < n; i++){
            v[i] = v[i - 1] + nums[i];
        }

        for(int i = 0; i < n - 1; i++){
            if(v[i] >= (v[n - 1] - v[i])) ans++;
        }

        return ans;
    }
};