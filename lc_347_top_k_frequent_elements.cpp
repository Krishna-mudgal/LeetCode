#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i : nums) m[i]++;

        int mx_freq = 0, s_mx_freq = 0;

        priority_queue<pair<int, int>> pq;
        for(auto p : m){
            pq.push({p.second, p.first});
        }

        while(k > 0){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }

        return ans;

    }
};