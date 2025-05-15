#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-one-row-to-tree/description/

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

//     void helper(TreeNode *r, int &val, int dep){
//         if(!r || dep == 0) return;

//         if(dep == 1){
//             TreeNode* lst = NULL;
//             if(r -> left) lst = r -> left;
//             TreeNode* rst = NULL;
//             if(r -> right) rst = r -> right;

//             TreeNode *t1 = new TreeNode(val);
//             TreeNode *t2 = new TreeNode(val);

//             r -> left = t1;
//             r -> right = t2;

//             t1 -> left = lst;
//             t2 -> right = rst;

//         }

//         helper(r -> left, val, dep - 1);
//         helper(r -> right, val, dep - 1);


//     }

//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth == 1) {
//             TreeNode *t = new TreeNode(val);
//             t -> left = root;
//             return t;
//         }
//         helper(root, val, depth - 1);
//         return root;
//     }
// };