#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/first-missing-positive/description/

class Solution { // t.c. : O(nlogn), s.c. : O(1)
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int x = 1;
        sort(nums.begin(), nums.end());

        for(int e : nums){
            if(e > x) return x;
            if(e == x) x++;
        }

        return x;

    }
};

class Solution { // t.c. : O(n), s.c. = O(1)
public:
    int firstMissingPositive(vector<int>& nums) {
        // using cycle sort
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i] < 0){
                i++;
                continue;
            }
            int correctIdx = nums[i]-1;
            if( nums[i] <= 0 || nums[i] > n ||i == correctIdx) i++;
            else if(nums[correctIdx] == nums[i]) i++;
            else swap(nums[i], nums[correctIdx]);
        }

        int a=1;
        for(int i=0; i<n; i++){
            if(nums[i] == a) a++;
            else return a;
        }
        return a;
    }
};