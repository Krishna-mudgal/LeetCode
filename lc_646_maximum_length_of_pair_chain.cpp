#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

bool cmpt(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmpt);
        int ans = 1;
        int prev = pairs[0][1];
        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[i][0] > prev) {
                ans++;
                prev = pairs[i][1];
            }
        }

        return ans;
    }
};

class Solution {
public:

    vector<vector<int>> dp;
    int helper(vector<vector<int>> &pairs, int idx, int last) {
        if(idx >= pairs.size()) return 0;
        if(dp[idx][last + 1001] != -1) return dp[idx][last + 1001];
        if(pairs[idx][0] > last) {
            int take = 1 + helper(pairs, idx + 1, pairs[idx][1]);
            int notTake = 0 + helper(pairs, idx + 1, last);
            return dp[idx][last + 1001] = max(take, notTake);
        } else {
            return dp[idx][last + 1001] = helper(pairs, idx + 1, last);
        }
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        dp.resize(pairs.size(), vector<int>(2003, -1));
        return helper(pairs, 0, -1001);
    }
};

class Solution {
public:

    vector<vector<int>> dp;
    int helper(vector<vector<int>> &pairs, int idx, int prevIdx) {
        if(idx >= pairs.size()) return 0;
        if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];
        if(prevIdx == -1 || pairs[idx][0] > pairs[prevIdx][1]) {
            int take = 1 + helper(pairs, idx + 1, idx);
            int notTake = 0 + helper(pairs, idx + 1, prevIdx);
            return dp[idx][prevIdx + 1] = max(take, notTake);
        } else {
            return dp[idx][prevIdx + 1] = helper(pairs, idx + 1, prevIdx);
        }
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        dp.resize(pairs.size(), vector<int>(2003, -1));
        return helper(pairs, 0, -1);
    }
};