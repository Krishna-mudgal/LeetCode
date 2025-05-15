#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/move-zeroes/description/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int noz = 0;

        int j = 0, i = -1;
        for(j = 0; j < n; j++){
            if(nums[j] == 0){
                i = j;
                break;
            }
        }

        if(i == -1) return;
        j = 0;

        while(j < n){
            if(nums[j] != 0){
               if(i < j){
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            j++;
        }
    }
};