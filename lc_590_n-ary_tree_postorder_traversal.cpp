#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

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
//     void helper(Node *r, vector<int> &ans){
//         if(!r) return ;

//         for(int i = 0 ; i < r -> children.size(); i++){
//             helper(r -> children[i], ans);
//         }

//         ans.push_back(r -> val);
//     }
//     vector<int> postorder(Node* root) {
//         vector<int> ans;

//         helper(root, ans);

//         return ans;
//     }
// };