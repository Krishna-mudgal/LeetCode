#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19

class Solution {
    public:
        int minOperations(vector<int>& nums) { // T.C. = O(3*n) == O(n)
            int n = nums.size();
    
            int ans = 0;
            int i = 0, j = 2;
            while(j < n){
    
                if(nums[i] == 0){
                    for(int k = i; k <= j; k++){
                        if(nums[k] == 0) nums[k] = 1;
                        else nums[k] = 0;
                    }
                    ans++;
                }
    
                // for(int i : nums) cout << i << " ";
                // cout << endl;
    
                i++;
                j++;
            }
    
            while(i < n){
                if(nums[i] == 0) return -1;
    
                i++;
            }
    
            return ans;
        }
    };