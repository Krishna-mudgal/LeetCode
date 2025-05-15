#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12

class Solution { // T.C. = O(log(n))
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size();
            int lo = 0, hi = n - 1;
            int n_idx = -1, p_idx = -1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                
                if(nums[mid] < 0) {
                    n_idx = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
    
            int non = n_idx + 1; // no of negative
    
            lo = 0, hi = n - 1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
    
                if(nums[mid] > 0){
                    p_idx = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
    
            }
    
            int nop = -1;
            if(p_idx != -1) nop = n - p_idx;
            else nop = 0;
    
            return max(non, nop);
        }
    };

class Solution { // T.C> = O(n)
    public:
        int maximumCount(vector<int>& nums) {
            int m = nums.size();
            int p = 0, n = 0;
    
            for(auto i : nums) {
                if(i > 0) p++;
                else if(i < 0) n++;
            }
    
            return max(p, n);
        }
    };