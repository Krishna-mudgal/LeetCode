#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

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
//     int maxDepth(Node* root) {
//         if(!root) return 0;

//         int lvl = 0;
//         for(int i = 0; i < root -> children.size(); i++){
//             lvl = max(lvl, maxDepth(root -> children[i]));
//         }

//         return 1 + lvl;
//     }
// };