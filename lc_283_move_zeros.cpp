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

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while(i < n - 1) {
            if(nums[i] == 0) {

                // i ke ange jb tk 0 a rha h tb tk skip
                // if not zero then swap it with nums[i]
                int j = i + 1;
                while(j < n && nums[j] == 0) j++; 

                if(j == n) break;
                swap(nums[i], nums[j]);
            }

            i++;
        }
    }
};