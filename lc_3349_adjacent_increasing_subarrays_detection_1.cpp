#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/

class Solution {
public:

    bool check(vector<int> &nums, int x, int &k){
        for(int i = x + 1; i < x + k && i < nums.size(); i++) if(nums[i-1] >= nums[i]) return false;

        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i <= n - k; i++){
            int a = i;
            int b = a + k;
            if(b <= n - k){
                if(check(nums, a, k) && check(nums, b, k)) return true;
            }
        }

        return false;
    }
};


class Solution { // another method
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1) return true;

        int i = 0;
        while(i < n) {
            if(i + 1 < n && nums[i] < nums[i + 1]) {
                int j = i;
                int cnt = 1;
                while(j + 1 < n && nums[j] < nums[j + 1] && j + 1 < i + k) {
                    cnt++;
                    j++;
                }
                if(cnt < k) {
                    i++;
                    continue;
                }

                j++;
                cnt = 1;
                while(j + 1 < n && nums[j] < nums[j + 1] && j + 1 < i + 2*k) {
                    cnt++;
                    j++;
                }

                if(cnt == k) return true;
                else i++;
            } else i++;
        }

        return false;
    }
};