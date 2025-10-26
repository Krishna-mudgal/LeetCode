#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/contiguous-array/description/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int  n = nums.size();
        int ans = 0, pSum = 0;
        unordered_map<int, int> mp;
        /*
            Isme 1 arha h to add 1 krdo or agr 0 arha h to -1 add krdo sum m
            ab agr jo current sum h wo phle bhi achuka h iska mtlv jo apne add kiya tha last time jb same aya tha wha se wo neutralize hochuka h iska mtlv first time jha pr yh sum mila tha wha se yha tk number of 1 = number of 0
        */
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) pSum += -1;
            else pSum += 1;

            if(mp.find(pSum) != mp.end()) ans = max(ans, i - mp[pSum]);
            else mp[pSum] = i;
        }
        return ans;
    }
};