#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/image-overlap/description/

class Solution {
public:

    int helper(vector<vector<int>>& img1, vector<vector<int>>& img2, int x_xtra, int y_xtra) {
        int n = img1.size();
        int ans = 0;
        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < n; j++) {
                int x_ = i + x_xtra;
                int y_ = j + y_xtra;
                if(x_ < n && x_ >= 0 && y_ < n && y_ >= 0 && img2[x_][y_] == 1 && img2[x_][y_] == img1[i][j]) ans++;
            }
        }

        return ans;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int ans = 0;
        for(int i = -n + 1; i < n; i++) {
            for(int j = -n + 1; j < n; j++) {
                ans = max(ans, helper(img1, img2, i, j));
            }
        }

        return ans;
    }
};