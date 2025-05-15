#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06

class Solution {
public:

    bool check_1(vector<int> &nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] > nums[i]) return false;
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        vector<int> v;
        while(j < n){
            if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[j])){
                v.push_back(nums[j]);
                j++;
            }
            else{
                sort(v.begin(), v.end());
                for(int k = i; k < j; k++) nums[k] = v[k - i];
                i = j;
                v.resize(0);
            }
        }

        if(!v.empty()){
            sort(v.begin(), v.end());
            for(int k = i; k < j; k++) nums[k] = v[k - i];
        }

        return check_1(nums);
    }
};