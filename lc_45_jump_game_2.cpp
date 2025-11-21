#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) { // bfs

        int n = nums.size();
        int ans = 0;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int m = q.size();
            for(int i = 0; i < m; i++) {
                auto t = q.front();
                q.pop();

                if(t == n - 1) return ans;

                for(int j = 1; j <= nums[t]; j++) {
                    if(t + j < n && !visited[t + j]) {
                        q.push(t + j);
                        visited[t + j] = true;
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};

class Solution { // dfs with dp
public:

    vector<long long> dp;
    long long helper(vector<int> &nums, int idx) {
        if(idx >= nums.size()) return INT_MAX;
        if(idx == nums.size() - 1) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;
        for(int i = 1; i <= nums[idx]; i++) {
            long long x = 1 + helper(nums, idx + i);
            if(ans > x) {
                ans = x; 
            }
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return helper(nums, 0);
    }
};
