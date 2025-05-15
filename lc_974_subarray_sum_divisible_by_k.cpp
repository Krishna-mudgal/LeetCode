#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 1; i < n; i++) nums[i] += nums[i - 1];

        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int rem = ((nums[i] % k) + k) % k; // to handle cases where nums[i] can be negative also

            if(m.find(rem) != m.end()){
                ans += m[rem];
            }

            m[rem]++;
        }

        return ans;

    }
};