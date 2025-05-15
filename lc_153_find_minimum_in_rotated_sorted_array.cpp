#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        // pivot is the smallest element so return pivot
        // pivot ke right m sorted array milega (including pivot also)

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[hi]) lo = mid + 1; // mid can't be a pivot bcs it is greater than hi so it can't be a pivot so no need to include it for next iteration
            else hi = mid; // mid can also be a pivot
        }

        return nums[hi];

    }
};