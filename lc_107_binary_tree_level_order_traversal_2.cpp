#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
// class Solution { // variation 1
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         if(root == NULL) return {};

//         queue<TreeNode *> q;
//         vector<vector<int>> ans;

//         q.push(root);

//         while(q.size() > 0){
//             int n = q.size();
//             vector<int> v;
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 v.push_back(t -> val);

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }

//             ans.push_back(v);
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
    
//     }
// };

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution { // variation 2
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         if(root == NULL) return {};

//         queue<TreeNode *> q;
//         vector<vector<int>> ans;

//         q.push(root);

//         while(q.size() > 0){
//             int n = q.size();
//             vector<int> v;
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 v.push_back(t -> val);

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }

//             ans.push_back(v);
//         }

//         stack<vector<int> > st;

//         for(int i = 0; i < ans.size(); i++) st.push(ans[i]);

//         ans.clear();
//         while(st.size() > 0){
//             auto v = st.top();
//             st.pop();

//             ans.push_back(v);
//         }

//         return ans;
    
//     }
// };