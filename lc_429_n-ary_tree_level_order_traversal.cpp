#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         if(!root) return {};
//         vector<vector<int>> ans;
        
//         queue<Node *> q;
//         q.push(root);

//         while(!q.empty()){
//             int n = q.size();
//             vector<int> v;
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 v.push_back(t -> val);

//                 int x = t -> children.size();
//                 for(int j = 0; j < x; j++){
//                     if(t -> children[j]) q.push(t -> children[j]);
//                 }

//             }
//             ans.push_back(v);
//         }

//         return ans;
//     }
// };