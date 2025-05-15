#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18

class Solution { // T.C. = O(n*30*30) = O(n)
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size();
            int ans = 1;
    
            int i = 0, j = 0;
            while(i < n){
                j = i + 1;
                while(j < n && j < i + 30){
                    bool flag = true;
                    for(int k = i; k < j; k++){
                        if((nums[k] & nums[j]) != 0) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) ans = max(ans, j - i + 1);
                    else break;
    
                    if(ans == 30) return 30;
    
                    j++;
                }
                i++;
            }
    
            // cout << (16384 & 217313281);
    
            return ans;
        }
    };