#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10

class Solution { // approach - 1
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int> > v;

        int ans = 0;
        v.push_back({nums[0], 0});
        for(int i = 1; i < n; i++){
            if(nums[i] < v[v.size() - 1].first) v.push_back({nums[i], i});
            else {
                for(int j = 0; j < v.size(); j++){
                    auto p = v[j];
                    if(p.first <= nums[i]){
                        int width = i - p.second;
                        ans = max(ans, width);
                        break;
                    }
                }
            }
        }

        return ans;

    }
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) { // approach - 2
        int n = nums.size();

        vector<pair<int, int> > v;
        int ans = 0;

        for(int i = 0; i < n; i++) v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        int mx_idx = v[n - 1].second;
        for(int i = n - 2; i >= 0; i--){
            if(mx_idx < v[i].second){
                mx_idx = v[i].second;
            }
            else{
                int width = mx_idx - v[i].second;
                ans = max(ans, width);
            }
        }

        return ans;

    }
};