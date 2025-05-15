#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        if(n < 2) return true;
        
        if((nums[n - 2] % 2 == 0 && nums[ n - 1] % 2 == 0) || (nums[n - 2] % 2 == 0 && nums[n - 1] % 2 == 0)) return false;
        for(int i = 0; i < n - 1; i++){
            if((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || nums[i] % 2 != 0 && nums[i + 1] % 2 != 0) return false;
        }

        return true;
    }
};