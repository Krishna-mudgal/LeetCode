#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-number-ii/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;

        for(int i : nums) m[i]++;

        for(auto i : m) if(i.second == 1) return i.first;

        return -1;
    }
};