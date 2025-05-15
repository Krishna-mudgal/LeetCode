#include <bits/stdc++.h>
using namespace std;

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
// class Solution { // brute force time : O(n2)
// public: 
//     void helper(TreeNode *child, TreeNode *root, int &ans){
//         if(root == NULL || child == NULL) return;

//         ans = max(ans, abs(child -> val - root -> val));

//         helper(child -> left, root, ans);
//         helper(child -> right, root, ans);

//     }
//     void travel(TreeNode *r, int &ans){
//         if(r == NULL) return;
        
//         helper(r -> left, r, ans);
//         helper(r -> right, r, ans);

//         travel(r -> left, ans);
//         travel(r -> right, ans);
//     }
//     int maxAncestorDiff(TreeNode* root) {
//         int ans = INT_MIN;
//         travel(root, ans);
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
// class Solution { // optimised : isme har ek root to leaf path mai max and min value nikala hai aur unka difference ans se compare kiya hai
// public: 
//     void travel_root_to_leaf(TreeNode *r, int max_val, int min_val, int &ans){
//         if(r == NULL) return;
        
//         max_val = max(max_val, r -> val);
//         min_val = min(min_val, r -> val);

//         if(!r -> left && !r -> right) ans = max(ans, abs(max_val - min_val)); // leaf node hai to hmne ek path to travel krhi liya hai to is path ka jo max aur min ka differnce hai usse ans ko compare krlo

//         travel_root_to_leaf(r -> left, max_val, min_val, ans);
//         travel_root_to_leaf(r -> right, max_val, min_val, ans);
//     }
//     int maxAncestorDiff(TreeNode* root) {
//         int ans = INT_MIN;
//         int max_value = root -> val;
//         int min_value = root -> val;
//         travel_root_to_leaf(root, max_value, min_value, ans);
//         return ans;
//     }
// };