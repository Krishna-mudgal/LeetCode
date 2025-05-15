#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/intersection-of-two-arrays/description/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        unordered_map<int, int> m1;
        vector<int> ans;

        for(int i = 0; i < n; i++) m1[nums1[i]]++;

        for(int i = 0; i < m; i++){
            if(m1.find(nums2[i]) != m1.end()){
                ans.push_back(nums2[i]);
                m1.erase(nums2[i]); // so that intersection wala element bar bar na dale
            }
        }

        return ans;
        
    }
};