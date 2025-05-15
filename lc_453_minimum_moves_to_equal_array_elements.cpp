#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // max element ko chod ko baki sb ko bdana is equal to min element ko chod ke baki sb ko ghatana

        int ans = 0;
        for(int i = 1 ; i < n; i++){
            ans += (nums[i] - nums[0]);
        }

        return ans;
    }
};