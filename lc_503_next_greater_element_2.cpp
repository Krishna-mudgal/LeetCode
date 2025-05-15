#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i = 0; i < n; i++){
            bool flag = true;
            for(int j = (i + 1) % n; j < n; j = (j + 1) % n){
                if(j == i) break;
                if(nums[j] > nums[i]) {
                    ans.push_back(nums[j]);
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(-1);
        }

        return ans;
    }
};