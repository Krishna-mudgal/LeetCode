#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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

//     void helper(TreeNode *r, vector<int> &v){
//         if(!r) return ;
        
//         helper(r -> left, v);
//         v.push_back(r -> val);
//         helper(r -> right, v);

//     }

//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v;
//         helper(root, v);
//         return v[k - 1];
//     }
// };