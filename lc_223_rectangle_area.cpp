#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rectangle-area/description/

class Solution {
public:
    
    int area(int &x1, int &y1, int &x2, int &y2){
        return abs(x2 - x1)*abs(y2 - y1);
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = area(ax1, ay1, ax2, ay2);
        int a2 = area(bx1, by1, bx2, by2);

        int cx1 = max(ax1, bx1);
        int cy1 = max(ay1, by1);
        int cx2 = min(ax2, bx2);
        int cy2 = min(ay2, by2);

        int common = 0;
        if(cx2 > cx1 && cy2 > cy1) common = area(cx1, cy1, cx2, cy2);

        return a1 + a2 - common;
    }
};