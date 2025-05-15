#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
    
            int ans = 0;
            int i = 0, j = 2;
            while(j < n){
    
                if(2*(nums[i] + nums[j]) == nums[(i + j)/2]) ans++;
                i++;
                j++;
            }
    
            // cout << -1/2;
    
            return ans;
        }
    };