#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();

        int ans = INT_MAX;

        for(int i = 1; i < n; i++){
            
            int l_h = (timePoints[i - 1][0] - '0')*10 + (timePoints[i - 1][1] - '0');
            int l_m = (timePoints[i - 1][3] - '0')*10 + (timePoints[i - 1][4] - '0');
            int h = (timePoints[i][0] - '0')*10 + (timePoints[i][1] - '0');
            int m = (timePoints[i][3] - '0')*10 + (timePoints[i][4] - '0');

            int m_diff = abs(l_h*60 - h*60 + l_m - m); // multiply by 60 to convert hours into minutes

            ans = min(ans,  m_diff); 

        }

        // checking first time point after sorting and last timepoint after sorting -> to check mid night value
        int s_h = (timePoints[0][0] - '0')*10 + (timePoints[0][1] - '0');
        int s_m = (timePoints[0][3] - '0')*10 + (timePoints[0][4] - '0');
        int e_h = (timePoints[n - 1][0] - '0')*10 + (timePoints[n - 1][1] - '0');
        int e_m = (timePoints[n - 1][3] - '0')*10 + (timePoints[n - 1][4] - '0');
        ans = min(ans, ((1440 - (e_h*60 + e_m)) + (s_h*60 +s_m)));

        return ans;
    }
};