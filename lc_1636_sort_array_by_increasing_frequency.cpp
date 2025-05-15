#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

class cmp{
public:

    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    }

};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i : nums) m[i]++;

        for(auto p : m) pq.push({p.second, p.first});

        vector<int> ans;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            for(int i = 0; i < p.first; i++){
                ans.push_back(p.second);
            }
        }

        return ans;

    }
};