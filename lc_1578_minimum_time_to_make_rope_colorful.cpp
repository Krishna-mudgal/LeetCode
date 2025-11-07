#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) { // T.C. = O(n)
        int n = colors.size();

        int ans = 0;
        int i = 0;
        while(i < n) {
            if(i + 1 < n && colors[i] == colors[i + 1]) {
                int j = i;
                int cnt = 0;
                int mxNeededTime = 0;
                while(j < n && colors[j] == colors[i]) {
                    cnt += neededTime[j];
                    mxNeededTime = max(mxNeededTime, neededTime[j]);
                    j++;
                }
                ans += (cnt - mxNeededTime);
                i = j;
            } else i++;
        }

        return ans;
    }
};