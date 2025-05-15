#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/button-with-longest-push-time/description/

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();
        int ans = events[0][0];
        int max_time = events[0][1];

        for(int i = 1; i < n; i++){
            int time = events[i][1] - events[i - 1][1];

            if(time > max_time){
                ans = events[i][0];
                max_time = time;
            }
            else if(time == max_time) ans = min(ans, events[i][0]);
        }

        return ans;
    }
};