#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    int binarySearch(vector<int> &nums, int lo, int hi, int tar){
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == tar) return mid;
            else if(nums[mid] > tar) hi = mid - 1;
            else lo = mid + 1;
        }

        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i = 0; i < n; i++){
            int rem = target - numbers[i];

            int idx = binarySearch(numbers, i + 1, n - 1, rem);

            if(idx != - 1) return {i + 1, idx + 1};

        }

        return {-1, -1};

    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { // Greedy
        int n = numbers.size();

        int lo = 0, hi = n - 1;

        while(lo < hi){
            if(numbers[lo] + numbers[hi] == target) return {lo + 1, hi + 1};
            else if(numbers[lo] + numbers[hi] > target) hi--;
            else lo++;
        }

        return {-1, -1};

    }
};