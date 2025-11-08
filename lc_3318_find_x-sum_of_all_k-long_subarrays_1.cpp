#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

class Solution {
public:

    int helper(vector<int> &v, int x) {
        sort(v.begin(), v.end());
        int n = v.size();

        int i = 0;
        vector<pair<int, int>> v2;
        while(i < n) {
            int j = i;
            int cnt = 0;
            while(j < n && v[j] == v[i]) {
                cnt++;
                j++;
            }
            v2.push_back({cnt, v[i]});
            i = j;
        }

        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());
        int ans = 0;
        for(int i = 0; i < x && i < v2.size(); i++) {
            ans += v2[i].first*v2[i].second;
        }

        return ans;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<int> v;
        for(int i = 0; i <= n - k; i++) {
            v.clear();
            for(int j = i; j < i + k && j < n; j++) {
                v.push_back(nums[j]);
            }
            ans.push_back(helper(v, x));
        }

        return ans;
    }
};