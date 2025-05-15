#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        int i = 0, j = 1;

        while(j < n){
            if(nums[j] > nums[j - 1]) {
                j++;
            }
            else{
                ans = max(ans, j - i);
                i = j;
                j++;
            }
        }

        return max(ans, j - i);;

    }
};