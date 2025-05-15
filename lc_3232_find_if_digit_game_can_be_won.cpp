#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-if-digit-game-can-be-won/description/

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int alice = 0, bob = 0;
        int n = nums.size();
        int alice2 = 0, bob2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] >= 10) bob += nums[i];
            else alice += nums[i];

            if(nums[i] >= 10 && nums[i] < 100) alice2 += nums[i];
            else bob2 += nums[i];
        }

        return ((alice > bob) || (alice2 > bob2));
    }
};