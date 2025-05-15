#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2025-04-29

class Solution { // T.C. = O(n)
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
    
            long long ans = 0;
            int i = 0, j = 0;
            int cnt = 0;
            int maxi = *max_element(nums.begin(), nums.end());
            while(j < n){
                if(nums[j] == maxi) cnt++;
    
                if(cnt >= k) {
                    ans += n - j;
                    while(cnt >= k){
                        if(maxi == nums[i]) cnt--;
                        i++;
                        if(cnt >= k) ans += n - j;
                    }
                }
    
                j++;
            }
    
            while(i < n){
                if(maxi == nums[i]) cnt--;
                i++;
                if(cnt >= k) ans++;
            }
    
            return ans;
        }
    };