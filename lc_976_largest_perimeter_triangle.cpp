#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        bool flag = false;
        for(int i = n - 1; i >= 0; i--) {
            flag = false;
            for(int j = i - 1; j >= 0; j--) {
                for(int k = j - 1; k >= 0; k--) {
                    if(nums[i] < nums[j] + nums[k]) {
                        ans = nums[i] + nums[j] + nums[k];
                        flag = true;
                        break;
                    } else break;
                }
                if(flag) break;
            }
            if(flag) break;
        }

        return ans;
    }
};