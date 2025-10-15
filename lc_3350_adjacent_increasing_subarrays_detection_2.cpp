#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/?envType=daily-question&envId=2025-10-15

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;
        int i = 0;
        while(i < n) {
            if(i + 1 < n && nums[i] < nums[i + 1]) {
                int j = i;
                int cnt = 1;
                while(j + 1 < n && nums[j] < nums[j + 1]) {
                    cnt++;
                    j++;
                }

                v.push_back({i, cnt});
                j++;
                i = j;
            } else i++;
        }

        int ans = 1;
        for(int i = 0; i < v.size(); i++) {
            ans = max(ans, v[i].second/2);
            if(i + 1 < v.size() && v[i].first + v[i].second == v[i + 1].first){
                ans = max(ans, min(v[i].second, v[i + 1].second));
            }
        }

        return ans;
    }
};