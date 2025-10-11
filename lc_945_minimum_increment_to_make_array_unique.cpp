#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i - 1]) {
                int x = nums[i];
                nums[i] = nums[i - 1] + 1;
                ans += nums[i] - x;
            }
        }

        return ans;
    }
};