#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        /*
            Similar to lc 530
            
            here if some thing is extra in cummulative sum then goal then find if that extra thing is seen before or not if it is seen then cummulative sum till that index is the extra thing than now if we romove that then we got the subarray whose sum is equal to the goal.
        */
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pSum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            pSum += nums[i];
            int extra = pSum - goal;

            if(mp.find(extra) != mp.end()) {
                ans += mp[extra];
            } 

            mp[pSum]++;
        }

        return ans;
    }
};