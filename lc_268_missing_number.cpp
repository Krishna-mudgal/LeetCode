#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/missing-number/

class Solution { // T.C. = O(n)
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long x = ((n+1)*n)/2;
        for(int i = 0; i < n; i++) {
            x -= nums[i];
        }

        return x;
    }
};

class Solution { // T.C. = O(n*log(n))
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), i=0;
        sort(nums.begin(), nums.end());
        if (nums[nums.size()-1] != nums.size()) return nums.size();
        while(i < n){
            if(i != nums[i]) return i;
            i++;
        }
        return -1;
    }
};