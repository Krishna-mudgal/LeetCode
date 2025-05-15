#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18

class Solution {
public:

    void helper(vector<int> &nums, int idx, int &ans, int &max_or, int c_or) {
        if(idx == nums.size()) {
            if(c_or == max_or) ans++;
            return;
        }

        if(c_or == max_or) ans++;

        int x = c_or;
        for(int i = idx; i < nums.size(); i++){
            x = x | nums[i];
            helper(nums, i + 1, ans, max_or, x);
            x = c_or;
        }
        
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int max_or = 0, ans = 0;

        for(int i = 0; i < n; i++){
            int x = nums[i];
            max_or = max(max_or, x);
            for(int j = i + 1 ; j < n; j++){
                x = x | nums[j];
                max_or = max(max_or, x);
            }
        }

        helper(nums, 0, ans, max_or, 0);
        
        return ans;

    }
};