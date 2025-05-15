#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/?envType=daily-question&envId=2024-12-16

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for(int i = 0; i < n; i++) pq.push({nums[i], i});

        while(k--){
            auto p = pq.top();
            pq.pop();

            pq.push({p.first*multiplier, p.second});
        }

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            nums[p.second] = p.first;
        }

        return nums;

    }
};