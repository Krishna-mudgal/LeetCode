#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        int f_mx = INT_MIN, s_mx = INT_MIN, t_mx = INT_MIN;

        for(int i = 0; i < n; i++) f_mx = max(f_mx, nums[i]);

        bool flag = true;
        for(int i = 0; i < n; i++){
            if(nums[i] == f_mx) continue;
            else if(s_mx <= nums[i]){
                s_mx = nums[i];
                flag = false;
            }
        }

        if(flag) return f_mx;

        flag = true;
        for(int i = 0 ; i < n; i++){
            if(nums[i] == f_mx || nums[i] == s_mx) continue;
            else if(t_mx <= nums[i]){
                t_mx = nums[i];
                flag = false;
            }
        }

        if(flag) return f_mx;

        return t_mx;


    }
};