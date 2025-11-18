#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:

    void dfs(vector<vector<int>> &isConnected, int currNode, vector<bool> &visited) {
        if(visited[currNode])  return;

        visited[currNode] = true;
        for(int i = 0; i < isConnected[currNode].size(); i++) {
            if(isConnected[currNode][i] && !visited[i]) dfs(isConnected, i, visited);
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ans++;
                dfs(isConnected, i, visited);
            }
        }

        return ans;
    }
};