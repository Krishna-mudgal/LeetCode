#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;

        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) != m.end()){ // duplicate occures
                if(abs(i - m[nums[i]]) <= k) return true;
            }

            m[nums[i]] = i;
        }

        return false;
    }
};