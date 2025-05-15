#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/monotonic-array/description/

class Solution {
    public:
        bool isMonotonic(vector<int>& nums) {
            int n = nums.size();
            bool flag = true;
    
            for(int i = 0; i < n - 1; i++){
                if(nums[i] > nums[i + 1]) {
                    flag = false;
                    break;
                }
            }
    
            if(flag) return true;
    
            flag = true;
            for(int i = 0; i < n - 1; i++){
                if(nums[i] < nums[i + 1]){
                    flag = false;
                    break;
                }
            }
    
            return flag;
        }
    };