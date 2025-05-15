#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        for(auto interval : intervals){
            if(pq.empty()) pq.push({interval[1], interval[0]});
            else{
                if(interval[0] <= pq.top().first) pq.push({interval[1], interval[0]});
                else if(interval[0] > pq.top().first){ // means pq.top() is exahusted
                    pq.pop(); // remove pq.top() bcs it is exahusted
                    pq.push({interval[1], interval[0]}); // push new group
                }
            }
        }

        return pq.size();

    }
};