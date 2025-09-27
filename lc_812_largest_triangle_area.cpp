#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-triangle-area/?envType=daily-question&envId=2025-09-27

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end());
        double ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], x2 = points[j][0], x3 = points[k][0];
                    int y1 = points[i][1], y2 = points[j][1], y3 = points[k][1];
                    ans = max(ans, 0.5*abs(x1*(double)(y2 - y3) + x2*(double)(y3 - y1) + x3*(double)(y1 - y2)));
                }
            }
        }

        return ans;
    }
};