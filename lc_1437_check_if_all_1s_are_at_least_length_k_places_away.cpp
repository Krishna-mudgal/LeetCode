#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/?envType=daily-question&envId=2025-11-17

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        for(int k = 0; k < n; k++) {
            if(nums[k] == 1){
                i = k;
                break;
            } 
        }
        j = i + 1;
        while(j < n) {
            while(j < n && nums[j] != 1) j++;
            if(j < n && j - i - 1 < k) return false;
            i = j;
            j++;
        }

        return true;
    }
};