#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/?envType=daily-question&envId=2025-05-30

class Solution { // T.C. = O(n)
public:

    void helper(unordered_map<int, int> &m, int current_node, vector<int> &v, unordered_set<int> &visited){
        
        if(visited.find(current_node) != visited.end()) return;

        v.push_back(current_node);
        visited.insert(current_node);
        if(m[current_node] != -1) helper(m, m[current_node], v, visited);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[i] = edges[i];
        }

        vector<int> v1, v2;
        unordered_set<int> visited;
        helper(m, node1, v1, visited);
        visited.clear();
        helper(m, node2, v2, visited);

        int ans = -1;
        unordered_map<int, int> m1;
        int dist = INT_MAX;
        for(int i = 0; i < v1.size(); i++){
            m1[v1[i]] = i;
        }
        for(int j = 0; j < v2.size(); j++){
            if(m1.find(v2[j]) != m1.end()){
                int curr_dist = max(j, m1[v2[j]]);
                if(curr_dist < dist){
                    ans = v2[j];
                    dist = curr_dist;
                }
                else if(curr_dist == dist) ans = min(ans, v2[j]);
            }
        }

        return ans;
    }
};