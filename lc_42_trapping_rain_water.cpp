#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        /*
            first find bar with max height then do following till max height bar:
                It starts from a non-zero height.
                Then looks for the next bar that is ≥ current bar (or the next peak).
                Counts the water trapped between the two by calculating:
                    total_area_between = (width) * (height of left bar)
                    minus sum of intermediate bar heights

            then do above from n - 1 to max height bar
        */

        int ans = 0;
        int i = 0;
        int mx_height_idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(height[i] > mx) {
                mx = height[i];
                mx_height_idx = i;
            }
        }

        while(i < n && height[i] == 0) i++;
        
        while(i <= mx_height_idx) {
            int j = i + 1;
            int x = 0;
            while(j <= mx_height_idx && height[j] < height[i]) {
                x -= height[j];
                j++;
            }

            x += (j - i - 1)*height[i];
            ans += x;
            i = j;
        }

        i = n - 1;
        while(i > mx_height_idx && height[i] == 0) i--;
        while(i > mx_height_idx) {
            int j = i - 1;
            int x = 0;
            while(j > mx_height_idx && height[j] < height[i]) {
                x -= height[j];
                j--;
            }

            x += (i - j - 1)*min(height[i], height[j]);
            ans += x;
            i = j;
        }

        return ans;
    }   
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev(n);
        int max = height[0];

        for(int i=1; i<n; i++)
        {
            if(height[i] > max) max = height[i];
            prev[i] = max;
        }
        max = height[n-1];
        for(int i=n-1; i>=0; i--)
        {
            if(height[i] > max) max = height[i];
            if(prev[i] > max) prev[i] = max;
        }
        int ans = 0;
        for(int i=1; i<=n-2; i++)
        {
            if(prev[i] > height[i]) ans += (prev[i] - height[i]);
        }
        return ans;
    }
};