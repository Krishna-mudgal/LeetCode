#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/

class Solution {
public:

    bool check(vector<int> &nums, int x, int &k){
        for(int i = x + 1; i < x + k && i < nums.size(); i++) if(nums[i-1] >= nums[i]) return false;

        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i <= n - k; i++){
            int a = i;
            int b = a + k;
            if(b <= n - k){
                if(check(nums, a, k) && check(nums, b, k)) return true;
            }
        }

        return false;
    }
};