#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size() ;

        sort(nums.begin(), nums.end());
        int major_ele = nums[0];
        int freq = 0;

        int c_freq = 0;
        int i = 0;
        while(i < n){
            if(i + 1 < n && nums[i] == nums[i + 1]) c_freq++;
            else if(n > 2 && i == n - 1 && nums[i] == nums[i - 1]) c_freq++;
            else c_freq = 0;

            if(nums[i] == major_ele) freq++;

            if(c_freq > freq) {
                major_ele = nums[i];
                freq = c_freq;
            }

            i++;
        }

        return major_ele;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size() ;

        unordered_map<int, int> mp;
        for(int &i : nums) mp[i]++;

        for(auto p : mp) if(p.second > n/2) return p.first;

        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using moore's voting algorithm

        int ele = nums[0];
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ele) cnt++;
            else cnt--;

            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
        }

        return ele;
    }
};