#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24

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
//    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         if(root1 == NULL && root2 == NULL) return true;
//         else if(!root1 || !root2) return false;

//         if(root1 -> val != root2 -> val) return false;

//         if(root1 -> left && root1 -> right && root2 -> left && root2 -> right && (root1 -> left -> val == root2 -> right -> val) && (root1 -> right -> val == root2 -> left -> val)) { // means dono ko swap krdo
//             TreeNode *t = root1 -> left;
//             root1 -> left = root1 -> right;
//             root1 -> right = t;
//         }
//         else if(root1 -> left && root2 -> right && root1 -> left -> val == root2 -> right -> val){ // means agr ek skwed h to usme check krlo khi opposite to ni h
//             TreeNode *t = root1 -> right;
//             root1 -> right = root1 -> left;
//             root1 -> left = t;
//         }
//         else if(root1 -> right && root2 -> left && root1 -> right -> val == root2 -> left -> val){ // means agr ek skwed h to usme check krlo khi opposite to ni h
//             TreeNode *t = root1 -> left;
//             root1 -> left = root1 -> right;
//             root1 -> right = t;
//         }

//         // search in l.s.t and r.s.t
//         return flipEquiv(root1 -> left, root2 -> left) && flipEquiv(root1 -> right, root2 -> right);

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
// class Solution { // approach 2
// public:
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         if(!root1 && !root2) return true;
//         if(!root1 || !root2) return false;
        
//         if(root1 -> val != root2 -> val) return false;

//         bool flip = (flipEquiv(root1 -> left, root2 -> right) && flipEquiv(root1 -> right, root2 -> left));
//         bool no_flip = (flipEquiv(root1 -> left, root2 -> left) && flipEquiv(root1 -> right, root2 -> right));

//         return flip || no_flip;
//     }
// };