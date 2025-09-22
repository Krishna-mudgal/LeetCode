#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22

class Solution { // T.C. = O(n), S.C. = O(n);
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;

        int ans = 0;
        int mx = -1;
        for(auto &p : mp) {
            if(p.second > mx) {
                ans = p.second;
                mx = p.second;
            } else if(p.second == mx) ans += p.second;
        }

        return ans;
    }
};