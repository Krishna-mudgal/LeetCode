#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15

class Solution {
    public:
    
        bool check(vector<int> &nums, int k, int x){ // In this function we are checking if x capability is possible or not
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= x){
                    cnt++;
                    i++; // to make sure we can't use adjacent items
                }
            }
    
            return cnt >= k;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int lo = *min_element(nums.begin(), nums.end());
            int hi = *max_element(nums.begin(), nums.end());
    
            int ans = INT_MAX;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2; 
    
                if(check(nums, k, mid)) { 
                    ans = min(ans, mid);
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
    
            return ans;
        }
    };