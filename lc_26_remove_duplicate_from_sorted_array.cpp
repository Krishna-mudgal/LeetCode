#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int i = 0; i < n; i++) st.insert(nums[i]);

        int i = 0;
        for(auto p : st) {
            nums[i] = p;
            i++;
        }

        return st.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int n = nums.size();


        vector<int> arr;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) continue;
            else arr.push_back(nums[i]);
        }


        for(int i = 0; i < arr.size(); i++) nums[i] = arr[i];

        return arr.size();
    } 
};