#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:

    int binarySearch(vector<int> &nums, int lo, int hi, int target){
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) { // approach -2

        int n = nums.size();
        // find pivot -> the smallest element
        // search from 0 to pivot-1 or pivot to n - 1

        int lo = 0, hi = n - 1;

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[hi]) lo = mid + 1; // mid can't be a pivot so no need to include it bcs it is greater than hi
            else hi = mid; // mid can also be a pivot so include it 
        }

        int pivot = hi;

        if(pivot == 0){
            return binarySearch(nums, 0, n - 1, target);
        }

        return (nums[0] <= target && nums[pivot - 1] >= target) ? binarySearch(nums, 0, pivot - 1, target) : binarySearch(nums, pivot, n - 1, target);
    }
};