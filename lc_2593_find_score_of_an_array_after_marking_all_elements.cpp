#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        long long score = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            if(s.find(p.second) == s.end()){
                score += p.first;
                s.insert(p.second);
                if(p.second != n - 1) s.insert(p.second + 1);
                if(p.second != 0) s.insert(p.second - 1);
            }
        }
        
        return score;

    }
};