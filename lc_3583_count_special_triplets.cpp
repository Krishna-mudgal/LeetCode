#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1000000007;
        unordered_map<int, int> mp1, mp2;
        long long ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            mp2[nums[i]]++;
        }
        for(int i : nums) {
            long long x = ((long long)i)*2;
            mp2[i]--;
            if(mp2[i] == 0) mp2.erase(i);
            if(mp1.find(x) != mp1.end() && mp2.find(x) != mp2.end()) {
                ans += (long long)mp1[x]*(long long)mp2[x];
                ans %= MOD;
            }

            mp1[i]++;
        }

        return ans;
    }
};