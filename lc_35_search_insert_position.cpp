#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-insert-position/?page=18

class Solution { // T.C. = O(log(n))
    public:
        int searchInsert(vector<int>& nums, int target) {
            int lo = 0, hi = nums.size() - 1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) hi = mid - 1;
                else lo = mid + 1;
            }
    
            return lo;
        }
    };