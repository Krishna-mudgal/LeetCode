#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/print-binary-tree/description/

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

//     int find_lvl(TreeNode *r){
//         if(!r) return 0;

//         return 1 + max(find_lvl(r -> left), find_lvl(r -> right));
//     }

//     vector<vector<string>> printTree(TreeNode* root) {
//         int ht = find_lvl(root) - 1;
//         int m = ht + 1;
//         int n = pow(2, ht + 1) - 1;

//         vector<vector<string> > ans(m, vector<string> (n, ""));

//         ans[0][(n - 1)/2] = to_string(root -> val);
//         int r = 0, c = (n-1)/2;

//         queue<pair<TreeNode *, pair<int, int>>> q;
//         if(root -> left) q.push({root -> left, {r + 1, (c - pow(2, ht - r - 1))}});
//         if(root -> right) q.push({root -> right, {r + 1, (c + pow(2, ht - r - 1))}});
//         while(q.size() > 0){
//             int a = q.size();

//             for(int i = 0; i < a; i++){
//                 auto t = q.front();
//                 q.pop();
                
//                 int r = t.second.first, c = t.second.second;
//                 ans[r][c] = to_string(t.first -> val);

//                 if(t.first -> left) q.push({t.first -> left, {r + 1, (c - pow(2, ht - r - 1))}});
//                 if(t.first -> right) q.push({t.first -> right, {r + 1, (c + pow(2, ht - r - 1))}});
//             }
//         }

//         return ans;

//     }
// };