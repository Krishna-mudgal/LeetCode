#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int j = 0, ans = 0;

        int cnt = 0;
        while(j < n){
            if(nums[j] == 1) cnt++;
            else if(nums[j] == 0){
                ans = max(ans, cnt);
                cnt = 0;
            }
            j++;
        }
        
        ans = max(ans, cnt);
        
        return ans;

    }
};