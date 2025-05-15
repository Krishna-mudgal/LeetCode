#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-average-subarray-i/description/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double ans = INT_MIN;

        double x = 0;
        for(int i = 0; i < k; i++){
            x += nums[i];
        }
        double avg = x/k;
        ans = avg;

        int i = 1, j = k;

        while(j < n){
            x += (-nums[i - 1] + nums[j]);
            avg = x/k;
            ans = max(ans, avg);

            i++;
            j++;
        }

        return ans;
    }
};