#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-harmonious-subsequence/description/

class Solution { // approach 1, time : O(nlogn), space : O(1);
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0, j = 0, ans = 0;

        while(j < n && i < n){
            if(nums[j] == nums[i] || nums[j] == nums[i] + 1) j++;
            else {
                if(nums[j - 1] == nums[i] + 1) ans = max(ans, j - i);
                while(i < j && nums[i] != nums[j] - 1) i++;
            }
        }

        if(i < j && nums[j - 1] == nums[i] + 1) ans = max(ans, j - i);

        if(ans == 1) return 0;
        else return ans;

    }
};

class Solution { // approach 2
public:
    int findLHS(vector<int>& nums) { // time : O(n), Space : O(n);
    
        int n = nums.size();

        unordered_map<int, int> m;

        int ans = 0;

        for(int i : nums) m[i]++;

        for(int i : nums){
            if(m.find(i + 1) != m.end()){
                ans = max(ans, m[i] + m[i + 1]);
            }
        }

        if(ans == 1) return 0;
        else return ans;

    }
};