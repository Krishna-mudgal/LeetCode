#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-14

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = INT_MIN;
        int idx = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(mx < nums[i]){
                mx = nums[i];
                idx = i;
            }
        }

        int ans = 0;

        int i = idx, j = idx;

        while(j < n){
            if(nums[j] == mx) j++;
            else {
                ans = max(ans, j - i);
                while(j < n && nums[j] != mx) j++;
                i = j;
            }
        }

        ans = max(ans, j - i);

        return ans;
    }
};