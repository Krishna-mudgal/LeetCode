#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:

    bool helper(vector<vector<int>> &g, unordered_set<int> &t, unordered_set<int> &safe, int idx, unordered_set<int> &visited){
        if(t.find(idx) != t.end() || safe.find(idx) != safe.end()) return true;
        if(visited.find(idx) != visited.end()) return false; // means there is a cycle

        bool flag = true;
        visited.insert(idx); // mark curren node as visited

        for(int i = 0; i < g[idx].size(); i++){
            flag = flag & helper(g, t, safe, g[idx][i], visited); // & -> to check all paths are leading to terminal node or not
            if(flag == false) break; // if there is any one path leading to wrong ans then our final ans is false so no need to check for remaining paths
        }

        visited.erase(idx); // after doing all travelling to all paths from current node, now we are moving backwards so remove current node from visited set, ans of this node (that is all paths from this node are ending at terminal node or not) will be saved in flag variable

        // this is for optimizing
        if(flag) safe.insert(idx); // if final ans for this node is true that means from this node all paths will end at terminal node so we can mark it as safe node

        return flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;

        unordered_set<int> terminal, visited, safe;
        for(int i = 0; i < n; i++){
            if(graph[i].size() == 0) terminal.insert(i);
        }

        for(int i = 0; i < n; i++){
            if(helper(graph, terminal, safe, i, visited)) ans.push_back(i);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};