#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-gap/description/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            int x = nums[i];
            int y ;
            if(i + 1 < n) y = nums[i + 1];
            else y = x;

            ans = max(ans, y - x);
        }

        return ans;

    }
};