#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution {
public:
    
    int check(int posi, auto &v){
        int n = v.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(v[posi] - v[i]);
        }

        return ans;
    }

    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        sort(nums.begin(), nums.end());

        if(n % 2 == 0){ // even
            int x = check(n/2, nums);
            ans = min(ans, x);
            x = check((n/2) - 1, nums);
            ans = min(ans, x);
        }
        else {
            ans = check(n/2, nums);
        }

        return ans;
    } 
};

class Solution {
public:
    
    int check(int posi, auto &v){
        int n = v.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(v[posi] - v[i]);
        }

        return ans;
    }

    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(), nums.end());

        int mid = n/2;

        for(int i = 0; i < n; i++) ans += abs(nums[i] - nums[mid]);

        return ans;
    } 
};