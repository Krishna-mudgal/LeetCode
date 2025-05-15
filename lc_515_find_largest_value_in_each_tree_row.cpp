#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-largest-value-in-each-tree-row/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         if(!root) return {};

//         queue<TreeNode *> q;
//         vector<int> ans;

//         q.push(root);
//         while(!q.empty()){
//             int n = q.size();
//             int mx = INT_MIN;
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 mx = max(mx, t -> val);

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }
//             ans.push_back(mx);
//         }

//         return ans;
//     }
// };