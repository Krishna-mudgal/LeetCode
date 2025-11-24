#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        vector<int> v1, v2;
        for(auto i : nums) {
            total += i;
            if(i % 3 == 1) {
                v1.push_back(i);
            } else if(i % 3 == 2) {
                v2.push_back(i);
            }
        }


        if(total % 3 == 0) return total;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if(total % 3 == 1) {
            int case1 = v1.size() >= 1 ? v1[0] : INT_MAX;
            int case2 = v2.size() >= 2 ? v2[0] + v2[1] : INT_MAX;
            return (case1 > case2) ? (total - case2) : (total - case1);
        } else {
            int case1 = v2.size() >= 1 ? v2[0] : INT_MAX;
            int case2 = v1.size() >= 2 ? v1[0] + v1[1] : INT_MAX;
            return (case1 > case2) ? (total - case2) : (total - case1);
        }
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int> &nums, int idx, int rem) {
        if(idx == nums.size()) {
            if(rem == 0) {
                return 0;
            }
            else return INT_MIN;
        }   
        if(dp[idx][rem] != -1) return dp[idx][rem];


        int take = nums[idx] + helper(nums, idx + 1, (rem + nums[idx]) % 3);
        int skip = helper(nums, idx + 1, rem);

        return dp[idx][rem] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(3, -1));
        return helper(nums, 0, 0);
    }
};