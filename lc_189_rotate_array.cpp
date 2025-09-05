#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;
        vector<int> v;
        int i = n - k;
        while(i < n) v.push_back(nums[i++]);

        for(int i = 0; i < n - k; i++) v.push_back(nums[i]);
        
        nums = move(v);
    }
};

class Solution {
public:

    void reverse(vector<int> &nums, int lo, int hi) {
        while(lo <= hi) swap(nums[lo++], nums[hi--]);
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};