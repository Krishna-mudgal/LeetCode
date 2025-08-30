#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { // O(n)
        int n = nums.size();
        vector<int> v = nums; 
        unordered_map<int, int> mp;
        for(int i = 1; i < n; i++) {
            v[i] += v[i - 1];
        }

        int ans = 0;
        mp[0]++;
        for(int &i : v) {
            int rem = i - k;
            if(mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[i]++;
        }

        return ans;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v = nums;
        unordered_map<int, int> mp;
        for(int i = 1; i < n; i++) {
            v[i] += v[i - 1];
        }

        int ans = 0;
        for(int &i : v) {
            int rem = i - k;
            if(mp.find(rem) != mp.end()) {
                ans += mp[rem];
                if(rem == 0) ans++;
            } else if(rem == 0) ans++;

            mp[i]++;
        }

        return ans;
    }
};

