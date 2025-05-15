#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/?envType=daily-question&envId=2025-04-17


class Solution { // T.C. = o(n^2)
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int ans = 0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(nums[i] == nums[j] && (i*j % k == 0)) ans++;
                }
            }
    
            return ans;
        }
    };
