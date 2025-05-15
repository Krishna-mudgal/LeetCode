#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/description/

class Solution { // optimized, approach 1
public:
    void helper(vector<int> nums, vector<vector<int> > &ans, int i){
        if(i >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]); // do something
            helper(nums, ans, i + 1); // explore
            swap(nums[i], nums[j]); // revert step 1
        }

    }
    vector<vector<int>> permute(vector<int>& nums) { // optimized one
        if(nums.size() == 1) return {{1}};

        vector<vector<int> > ans;
        helper(nums, ans, 0);

        return ans;

    }
};

class Solution { // another approach
public:
    void helper(vector<int> &nums, vector<vector<int> > &ans, unordered_set<int> &s, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
                temp.push_back(nums[i]);
                helper(nums, ans, s, temp);
                s.erase(nums[i]);
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) { //  std approach to find permutations
        if(nums.size() == 1) return {{1}};

        vector<vector<int> > ans;
        unordered_set<int> s;
        vector<int> t;

        helper(nums, ans, s, t);
        
        return ans;
    }
};