#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element-ii/

class Solution { // approach - 1, time : O(n), space : O(n)
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int threshold = n/3;

        unordered_map<int, int> m;
        unordered_set<int> s;

        for(int i = 0; i < n; i++){
            m[nums[i]]++;
            if(m[nums[i]] > threshold) s.insert(nums[i]);
        }

        vector<int> ans(s.begin(), s.end());

        return ans;

    }
};

class Solution { // approach - 2, time : O(nlogn), space : O(1)
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int threshold = n/3;

        vector<int> ans;

        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n){
            int cnt = 1;

            while(i + 1 < n && nums[i] == nums[i + 1]){
                cnt++;
                i++;
            }

            if(cnt > threshold) ans.push_back(nums[i]);
            i++;
        }

        return ans;

    }
};