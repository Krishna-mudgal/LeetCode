#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subsets-ii/description/

class Solution {
    public:
        int n;
    
        void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> v, int idx){
            if(idx == n) {
                ans.push_back(v);
                return;
            }
    
            // take
            v.push_back(nums[idx]);
            helper(nums, ans, v, idx + 1);
    
            // not take : isme jitne bhi age elements hai jo ki equal hai nums[idx] ke unko apn ko skip krna hai aur sidha us index pr call krna hai jha pr nums[idx] different ho to iske liye hum ek loop use kr skte hai
            v.pop_back();
            int j = idx + 1;
            while(j < n && nums[j] == nums[idx]) j++;
            helper(nums, ans, v, j);
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            n = nums.size();
            vector<vector<int>> ans;
            vector<int> v;
            sort(begin(nums), end(nums));
    
            helper(nums, ans, v, 0);
    
            return ans;
        }
    };

    class Solution {
        public:
            void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalAns, int idx){
                if(idx == nums.size()){
                    finalAns.push_back(ans);
                    return;
                }
                if(ans.size() == 0) helper(nums, ans, finalAns, idx+1);
                else if(nums[idx] != ans[ans.size()-1]) helper(nums, ans, finalAns, idx+1);
                ans.push_back(nums[idx]);
                helper(nums, ans, finalAns, idx+1);
            }
            vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                sort(nums.begin(), nums.end());
                vector<int> ans;
                vector<vector<int>> finalAns;
                helper(nums, ans, finalAns, 0);
                return finalAns;
            }
        };