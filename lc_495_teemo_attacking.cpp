#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/teemo-attacking/description/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ans = 0;

        int last_poison = 0, i = 0;

        while(i < n){

            int curr_poison = timeSeries[i] + duration - 1;

            if(timeSeries[i] > last_poison) ans += duration; // if attacking time is greater than last poison end then add whole new duration
            else if(timeSeries[i] < last_poison) ans += (curr_poison - last_poison); //  if there is overlapping then add only that part which is not overlapping
            else ans += duration - 1; // if last poison end is equal to curr attacking time then add duratiion -1 bcs attacking time is already covered

            i++;
            last_poison = curr_poison;
        }

        if(timeSeries[0] == 0) return ans + 1;
        else return ans;

    }
};