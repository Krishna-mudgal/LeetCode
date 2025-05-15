#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
// class Solution { // in case of binary search tree we can compare with it's previous only
// public:
//     void inorder(TreeNode *root, int &ans, TreeNode *&prev){ // inorder is a sorted array so here if we take adjacent nodes than we will get minimum difference
//         if(root == NULL) return;

//         inorder(root -> left, ans, prev);

//         if(prev && ans > abs((root -> val) - (prev -> val))) ans = abs((root -> val) - (prev -> val));

//         prev = root;
//         inorder(root -> right, ans, prev);

//     }
//     int getMinimumDifference(TreeNode* root) {

//         int ans = INT_MAX;
//         TreeNode *prev = NULL;

//         inorder(root, ans, prev);

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
// class Solution { // for binary tree
// public:
//     TreeNode *start;
//     void travel(TreeNode *curr, TreeNode * t, int &ans){
//         if(curr == NULL) return ;

//         if(curr != t && abs((curr -> val) - (t -> val)) < ans) ans = abs((curr -> val) - (t -> val));

//         if(t -> left) travel(curr, t -> left, ans);
//         if(t -> right) travel(curr, t -> right, ans);
//     }

//     void helper(TreeNode *root, int &ans){
//         if(root == NULL) return;

//         travel(root, start, ans);

//         if(root -> left) helper(root -> left, ans);
//         if(root -> right) helper(root -> right, ans);

//     }
//     int getMinimumDifference(TreeNode* root) {
//         start = root;

//         int ans = INT_MAX;

//         helper(root, ans);

//         return ans;
        
//     }
// };