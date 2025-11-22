#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/?envType=daily-question&envId=2025-11-22

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums) if(i % 3 != 0) ans++;

        return ans;
    }
};