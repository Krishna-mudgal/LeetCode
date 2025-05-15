#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0, j = 0;
        while(j < n){
            if((nums[j] - nums[i]) <= 2*k) {
                j++;
                ans = max(ans, j - i);
            }
            else i++;
        }

        return ans;
    }
};