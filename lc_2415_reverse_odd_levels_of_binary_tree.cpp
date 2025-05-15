#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/?envType=daily-question&envId=2024-12-20

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
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         queue<TreeNode *> q;
//         q.push(root);
//         vector<TreeNode *> v;
//         vector<int> v2;
//         int lvl = 0;
//         while(q.size() > 0){
//             int n = q.size();
//             v.resize(0);
//             v2.resize(0);
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 v.push_back(t);
//                 v2.push_back(t -> val);
                
//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }

//             if(lvl % 2 != 0){
//                 reverse(v2.begin(), v2.end());

//                 for(int i = 0; i < v2.size(); i++){
//                     v[i] -> val = v2[i];
//                 }
//             }

//             lvl++;
//         }

//         return root;
//     }
// };

// LITTLE BIT DIFFERENT APPROACH

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
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         queue<TreeNode *> q;
//         q.push(root);
//         vector<TreeNode *> v;
//         int lvl = 0;
//         while(q.size() > 0){
//             int n = q.size();
//             v.resize(0);
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 v.push_back(t);
                
//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }

//             if(lvl % 2 != 0){
//                 for(int i = 0; i < (v.size())/2; i++){
//                     swap(v[i] -> val, v[v.size() - i - 1] -> val);
//                 }
//             }

//             lvl++;
//         }

//         return root;
//     }
// };