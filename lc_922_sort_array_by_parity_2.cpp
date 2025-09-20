#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-array-by-parity-ii/description/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0, j = 1;
        while(i < n && j < n) {
            if(nums[i] % 2 != 0) {
                swap(nums[j], nums[i]);
                j += 2;
            } else if(nums[j] % 2 == 0) {
                swap(nums[j], nums[i]);
                i += 2;
            } else if(nums[i] % 2 == 0) i += 2;
            else j += 2;
        }

        return nums;
    }
};

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for(int i : nums) (i % 2 == 0) ? (even.push_back(i)) : (odd.push_back(i));

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                ans.push_back(even.back());
                even.pop_back();
            } else {
                ans.push_back(odd.back());
                odd.pop_back();
            }
        }

        return ans;
    }
};