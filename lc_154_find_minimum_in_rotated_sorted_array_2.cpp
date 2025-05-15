#include <bits/stdc++.h>
using namespace std;

class Solution { // simple approach, time : O(n)
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        for(int i : nums) ans = min(ans, i);

        return ans;
    }
};

class Solution { // time : O(logn), optimized
public:

    int findPivot(vector<int> &nums, int lo, int hi){
        
        while(lo < hi && nums[lo] == nums[lo + 1]) lo++; // skip duplicates of left part

        while(lo < hi && nums[hi] == nums[hi - 1]) hi--; // skip duplicates of right part

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[hi]) lo = mid + 1; // mid can't be a pivot bcs it is greater than hi so no need to include it for next iteration
            else hi = mid; // mid can be a pivot so include it
        }

        return hi;
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        int lo = 0, hi = n - 1, x = n - 1;

        int pivot = findPivot(nums, lo, hi); // pivot is the smallest element

        return nums[pivot];
    }
};


