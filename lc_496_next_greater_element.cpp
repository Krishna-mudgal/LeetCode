#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i = 0; i < m; i++) mp[nums2[i]] = i;
        
        for(int i = 0; i < n; i++){
            int n2_idx = mp[nums1[i]];
            bool flag = true;

            for(int j = n2_idx ; j < m; j++){
                if(nums2[j] > nums1[i]){
                    ans.push_back(nums2[j]);
                    flag = false;
                    break;
                }
            }

            if(flag) ans.push_back(-1);
        }

        return ans;
    }
};