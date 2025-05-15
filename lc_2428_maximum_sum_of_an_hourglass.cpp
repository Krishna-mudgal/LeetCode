#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();

        int ans = 0;

        for(int i = 0; i <= m - 3; i++){
            for(int j = 0; j <= (grid[i].size() - 3); j++){
                int sum = (grid[i][j] + grid[i][j + 1] + grid[i][j + 2]);
                sum += grid[i + 1][j + 1];
                sum += (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]);

                ans = max(ans, sum);
            }
        }

        return ans;

    }
};