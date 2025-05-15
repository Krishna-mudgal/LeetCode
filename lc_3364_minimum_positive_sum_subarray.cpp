#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-positive-sum-subarray/description/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = l; i <= r; i++){
            int lo = 0, hi = 0;
            int cnt = 0;
            while(hi < i){
                cnt += nums[hi];
                hi++;
            }
            if(cnt > 0) ans = min(ans, cnt);
            while(hi < n){
                cnt -= nums[lo];
                lo++;
                cnt += nums[hi];
                hi++;
                if(cnt > 0) ans = min(ans, cnt);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};