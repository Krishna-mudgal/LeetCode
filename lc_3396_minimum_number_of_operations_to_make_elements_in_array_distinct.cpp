#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08

class Solution {
    public:
    
        bool check(vector<int> &nums){
            vector<int> v(101, 0);
            for(auto i : nums){
                if(v[i] > 0)  return false;
    
                v[i]++;
            }
    
            return true;
        }
    
        int minimumOperations(vector<int>& nums) {
            int ans = 0;
            int n = nums.size();
            
            for(int i = 0; i < n/2; i++) swap(nums[i], nums[n - i - 1]);
    
            if(check(nums)) return ans;
    
            while(!nums.empty()){
                ans++;
    
                nums.pop_back();
                if(nums.empty()) return ans;
                nums.pop_back();
                if(nums.empty()) return ans;
                nums.pop_back();
            
                if(check(nums)) return ans;
            }
    
            return ans;
        }
    };