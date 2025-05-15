#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2024-11-13

class Solution {
public:
    int l_bs(vector<int> &nums, int rem, int lo, int hi){
        // int lo = 0, hi = nums.size() - 1; // isko krne se ans ni a rha tha

        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] < rem){
                lo = mid + 1;
            }
            else {
                ans = mid;
                hi = mid - 1;
            }

        }

        return ans;
    }

    int r_bs(vector<int> &nums, int rem, int lo, int hi){
        // int lo = 0, hi = nums.size() - 1; // isko krne se ans ni a rha tha
        int ans = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] <= rem){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
    }
    

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        for(int i = 0; i < n; i++){
            int x = -1;
            int y = -1;
            x = l_bs(nums, lower - nums[i], i + 1, n - 1); // nums[i] + nums[j] >= lower -> nums[j] >= lower - nums[i] -> rem <= nums[j]
            y = r_bs(nums, upper - nums[i], i + 1, n - 1); // nums[i] + nums[j] <= upper -> nums[j] <= upper - nums[i] -> rem >= nums[j]

            if(x == -1 || y == -1) continue;

            if(i < y && y >= x) ans += (y - x + 1);
        }
        
        return ans;
    }
};
