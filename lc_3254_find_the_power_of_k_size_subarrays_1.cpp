#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/?envType=daily-question&envId=2024-11-16

class Solution { // brute force
public:

    int get(vector<int> &nums, int &i, int &j){
        
        int mx = nums[i];
        int x = nums[i];
        for(int k = i; k <= j; k++){
            if(x != nums[k]) return -1;
            mx = max(mx, nums[k]);

            x++;
        }

        return mx;
    }
    
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = k - 1;
        vector<int> ans;
        
        while(j < n){
            ans.push_back(get(nums, i, j));

            i++;
            j++;
        }

        return ans;
    }
};