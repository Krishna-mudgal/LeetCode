#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n = nums1.size(), m = nums2.size();
            int i = 0, j = 0, k = 0;
            vector<vector<int>> ans;
    
            while(i < n || j < m){
                if(i >= n || (j < m && nums1[i][0] > nums2[j][0])) {
                    ans.push_back({nums2[j][0], nums2[j++][1]});
                }
                else if(j >= m || (i < n && nums1[i][0] < nums2[j][0])) {
                    ans.push_back({nums1[i][0], nums1[i++][1]});
                }
                else {
                    ans.push_back({nums1[i][0], nums1[i++][1] + nums2[j++][1]});
                }
            }
    
            return ans;
        }
    };