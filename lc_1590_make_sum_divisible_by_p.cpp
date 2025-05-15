#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-sum-divisible-by-p/description/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long int total_sum = nums[0];
        vector<long long int> v(n);
        v[0] = nums[0] % p;

        for(int i = 1; i < n; i++){
            v[i] = (nums[i] + v[i - 1]) % p;
            total_sum += nums[i];
        }

        int remove;
        if(total_sum % p == 0) return 0;
        else remove = total_sum % p;

        // cout << total_sum << " " << remove << endl;

        int i = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = INT_MAX;
        while(i < n){ // to find subarray whose sum = remove
            int rem = (v[i] - remove + p) % p;
            
            if(m.find(rem) != m.end()) {
                ans = min(ans, i - m[rem]);
            }

            m[v[i] % p] = i;
            i++;
        }

        return (ans >= n) ? -1 : ans;

    }
};