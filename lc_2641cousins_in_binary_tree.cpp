#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23

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
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         queue<TreeNode *> q;
//         q.push(root);

//         vector<int> v;
//         while(!q.empty()){
//             int n = q.size();

//             int sum = 0;
//             for(int i = 0; i < n ;i++){
//                 auto t = q.front();
//                 q.pop();

//                 sum += t -> val;

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }
//             v.push_back(sum);
//         }

//         q.push(root);

//         int lvl = 1;
//         while(!q.empty()){
//             int n = q.size();

//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 // both childs ko haal ke haal change krdo
//                 int sum = 0;
//                 if(t -> left) sum += t -> left -> val;
//                 if(t -> right) sum += t -> right -> val;

//                 if(t -> left) t -> left -> val = v[lvl] - sum;
//                 if(t -> right) t -> right -> val = v[lvl] - sum;

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);

//             }

//             lvl++;
//         }

//         root -> val = 0;

//         return root;
//     }
// };