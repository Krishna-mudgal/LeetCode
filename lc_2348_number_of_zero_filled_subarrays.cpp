#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/?envType=daily-question&envId=2025-08-19

class Solution { // T.C. = O(n)
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        long long ans = 0;
        while(i < n ) {
            if(nums[i] == 0) {
                j = i;
                while(j < n && nums[j] == 0){
                    ans += (j - i + 1);
                    j++;
                }
                
                i = j;
            } else i++;
        }

        return ans;
    }
};