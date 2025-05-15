#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                ans += __builtin_popcount(nums[i] ^ nums[j]);
            }
        }

        return ans;
    }
};

class Solution { // optimal approach
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < 32; i++){
            int cnt1 = 0, cnt0 = 0;
            // ek ek karke sare no.s ki ith bit nikalo aur dekho ki 1 h ki 0 if 1 then add it in cnt1 otherwise in cnt0
            for(int i = 0; i < n; i++){
                int x = nums[i] & 1;
                if(x == 1) cnt1++;
                else cnt0++;

                nums[i] = nums[i] >> 1;
            }
            // ab unke combinations add krdo jitni bit different h unke
            ans += (cnt1*cnt0); // add combinations of 1s and 0s
        }

        return ans;
    }
};