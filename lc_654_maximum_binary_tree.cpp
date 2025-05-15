#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-binary-tree/description/

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

//     TreeNode *helper(vector<int> &nums, int lo, int hi){
//         if(hi < lo) return NULL;

//         int mx = INT_MIN;
//         int idx = -1;
//         for(int i = lo; i <= hi; i++){
//             if(mx < nums[i]){
//                 mx = nums[i];
//                 idx = i;
//             }
//         }

//         TreeNode *r = new TreeNode(mx);

//         r -> left = helper(nums, lo, idx - 1);
//         r -> right = helper(nums, idx + 1, hi);

//         return r;
//     }

//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         int n = nums.size();
//         return helper(nums, 0, n - 1);
//     }
// };  