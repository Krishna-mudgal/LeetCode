#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/

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
    
//     void helper2(TreeNode *r, int &sum, int &x){
//         if(!r) return;

//         sum += r -> val;
//         x++;

//         helper2(r -> left, sum, x);
//         helper2(r -> right, sum, x);
//     }

//     void helper(TreeNode *r, int &ans){
//         if(!r) return ;

//         int sum = 0, x = 0;
//         helper2(r, sum, x);
//         if((sum/x) == r -> val) ans++;

//         helper(r -> left, ans);
//         helper(r -> right, ans);
//     }
//     int averageOfSubtree(TreeNode* root) {
//         int ans = 0;
//         helper(root, ans);
//         return ans;
//     }
// };