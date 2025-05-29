#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-question&envId=2025-05-28

class Solution {
public:

    void helper(unordered_map<int, unordered_set<int>> &edges, unordered_map<int, vector<int>> &m, int &starting_node ,int current_node, int no_of_edges, int &k, unordered_set<int> &seen){
        if(no_of_edges > k || (seen.find(current_node) != seen.end())) return;
        else {
            m[starting_node].push_back(current_node);
        }

        seen.insert(current_node);

        for(auto i : edges[current_node]){
            helper(edges, m, starting_node, i, no_of_edges + 1, k, seen);
        }
    }

    void helper_2(unordered_map<int, unordered_set<int>> &edges, int &no_of_nodes, int current_node, int k, int no_of_edges, unordered_set<int> &seen){
        if(no_of_edges > k || (seen.find(current_node) != seen.end())) return;

        seen.insert(current_node);
        no_of_nodes++;

        for(auto i : edges[current_node]) {
            helper_2(edges, no_of_nodes, i, k, no_of_edges + 1, seen);
        }

    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, unordered_set<int>> edges;

        for(auto v : edges1) {
            edges[v[0]].insert(v[1]);
            edges[v[1]].insert(v[0]);
        }
        
        for(auto v : edges2) {
            edges[v[0] + edges1.size() + 1].insert(v[1] + edges1.size() + 1);
            edges[v[1] + edges1.size() + 1].insert(v[0] + edges1.size() + 1);
        }

        unordered_set<int> seen;

        // tree2 me hr node pr dekho ki within "k - 1" (k - 1 isliye kyu ki 1 edge tree1 ke node or trr2 ke node krne m chla gya) duri pr kitne nodes mil rhe h to jha pr max nodes mil rhe h usi ko save krlo no_of_nodes_by_tree_2 m
        //  phir baad me hr ek node of tree1 me with k duri pr kitne node mil rhe h usko ans vector m daalo or sath m no_of_nodes_by_tree_2 ko add krdo 

        int no_of_nodes_by_tree_2 = 0;
        unordered_map<int, vector<int>> temp_m;
        for(int i = 0; i <= edges2.size(); i++){
            i +=  edges1.size() + 1;
            seen.clear();

            int x = 0;
            helper_2(edges, x, i,k - 1, 0, seen);
            no_of_nodes_by_tree_2 = max(no_of_nodes_by_tree_2, x);
            i -=  edges1.size() + 1;
        }
        // cout << no_of_nodes_by_tree_2 << endl;
        // for(auto p : edges) {
        //     cout << p.first << " ";
        //     for(auto i : p.second) cout << i << " ";
        //     cout << endl;
        // }

        for(int i = 0; i <= edges1.size(); i++){
            seen.clear();
            helper(edges, m, i, i, 0, k, seen);
        }

        vector<int> ans;
        for(int i = 0; i <= edges1.size(); i++){
            ans.push_back(m[i].size() + no_of_nodes_by_tree_2);
        }

        return ans;


    }
};