#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-integer-added-to-array-i/description/

class Solution { // t.c. = O(nlogn)
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return nums2[0] - nums1[0];
    }
};


class Solution { // t.c = O(n)
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int mn1 = INT_MAX, mn2 = INT_MAX;

        for(int ele : nums1) mn1 = min(mn1, ele);
        for(int ele : nums2) mn2 = min(mn2, ele);

        return mn2 - mn1;
    }
};