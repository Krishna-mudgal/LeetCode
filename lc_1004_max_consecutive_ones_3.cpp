#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int mxLen = 0;
        int i = 0, j = 0;
        while(j < n){
            if(nums[j] == 0){
                if(k <= 0){
                    while(k <= 0){
                        if(nums[i] == 0) k++;

                        i++;
                    }
                }
                k--; // converting 0 to 1
            }

            j++;
            mxLen = max(mxLen, j - i);
        }

        return mxLen;
    }
};