#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/?envType=daily-question&envId=2025-04-03

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            // at particular point j we need to find max value on its left side and right side
            // so pre_max is used to store max value till the current idx starting from idx 0, so we get - on a particular point max value in it's left
            // and suff_max is used to store max value till the current idx from it's end, so on a particular point we get max value from it's right
            vector<int> pre_max(n);
            vector<int> suff_max(n);
    
            int mx = -1;
            for(int i = 0; i < n; i++){
                if(mx < nums[i]){
                    mx = nums[i];
                }
    
                pre_max[i] = mx;
    
                // cout << pre_max[i] << " ";
            }
            // cout << endl;
    
            mx = -1;
            for(int i = n - 1; i >= 0; i--){
                if(mx < nums[i]){
                    mx = nums[i];
                }
    
                suff_max[i] = mx;
            }     
    
            // for(auto i : suff_max)  cout << i << " ";
    
            long long ans =0;
            for(int i = 1; i < n - 1; i++){
                ans = max(ans, ((long long)(pre_max[i - 1] - nums[i]) * suff_max[i + 1]));
            }
    
            return ans;
        }
    };