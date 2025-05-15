#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/deepest-leaves-sum/description/

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
//     int deepestLeavesSum(TreeNode* root) {
//         int lvl = find_lvl(root);

//         queue<TreeNode *> q;
//         q.push(root);

//         int cnt = 1;
//         int ans = 0;
//         while(!q.empty()){
//             int n = q.size();
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 if(cnt == lvl) ans += t -> val;

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }
//             cnt++;
//         }

//         return ans;
//     }
// };

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
// class Solution { // more better approach
// public:
//     int deepestLeavesSum(TreeNode* root) {

//         queue<TreeNode *> q;
//         q.push(root);

//         int cnt = 1;
//         int ans = 0;
//         while(!q.empty()){
//             int n = q.size();
//             ans = 0;
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 ans += t -> val;

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }
//             cnt++;
//         }

//         return ans;
//     }
// };