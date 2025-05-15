#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            if(j != n - 1 && nums[j + 1] == nums[j] + 1) j++;
            else { 
                if(i == j) ans.push_back(to_string(nums[i]));
                else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                j++;
                i = j;
            }
        }

        return ans;
    }
};