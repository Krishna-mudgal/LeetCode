#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

// class Solution { // T.C = O(n) // adhora h yh solution
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         unordered_map<int, int> m; // freq map

//         for(int i = 0; i < n; i++) m[nums[i]]++;

//         vector<int> v;
//         for(auto p : m){
//             if(p.second == 1) v.push_back(p.first);
//             else if(p.second >= 2){
//                 v.push_back(p.first);
//                 v.push_back(p.first);
//             }
//         }

//         sort(v.begin(), v.end());
//         ans = v.size();

//         for(int i = 0; i < v.size(); i++) nums[i] = v[i];

//         return ans;

//     }
// };

class Solution { // optimized approach
public:

    int findPivot(vector<int> &nums, int lo, int hi){

        while(lo < hi && nums[lo] == nums[lo + 1]) lo++; // skip duplicate part from left

        while(lo < hi && nums[hi] == nums[hi - 1]) hi--; // skip duplicate part from right

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[hi]) lo = mid + 1; // mid can't be a pivot bsc mid is greater than hi so no neet to include it for next iteration
            else hi = mid; // mid can also be a pivot so include it
        }
        
        return hi;

    }

    bool binarySearch(vector<int> &nums, int lo, int hi, int target){
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target) return true;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) { // time : O(logn)
        int n = nums.size();

        int lo = 0, hi = n - 1;

        int pivot = findPivot(nums, lo, hi);
        
        if(pivot == 0) return binarySearch(nums, 0, n - 1, target);

        return (nums[0] <= target && nums[pivot - 1] >= target) ? binarySearch(nums, 0, pivot - 1, target) : binarySearch(nums, pivot, n - 1, target);

    }
};