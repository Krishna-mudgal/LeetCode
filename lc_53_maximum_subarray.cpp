#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kdane's algorithm
        int n = nums.size();
        
        int sum = 0; // sum agr mera positive h to me usko carry kruga next element ke liye bhi agr negative hua to ni kruga ku ki sum + nextEle < nextEle bcs sum is < 0, ab agr mera sum positive h to m use carry kruga because if sum + nextEle > nextEle because sum is > 0

        int maxi = INT_MIN;
        for(int i : nums) {
            sum += i;
            maxi = max(maxi, sum);

            if(sum < 0) sum = 0; // if sum is negative i will not carry it because it is going to decrease the resultant of addition of sum and next element so will consider a new whole subarray from nextEle and hence done sum = 0;
        }

        return maxi;
    }
};