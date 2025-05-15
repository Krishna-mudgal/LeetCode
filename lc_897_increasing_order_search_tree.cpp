#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/increasing-order-search-tree/description/

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


// class Solution { // T.C. = O(n)
//     public:
    
//         void in_order(TreeNode *r, queue<TreeNode *> &q){
//             if(!r) return;
    
//             in_order(r -> left, q);
//             q.push(r);
//             in_order(r -> right, q);
//         }
    
//         TreeNode* increasingBST(TreeNode* root) {
//             queue<TreeNode *> q;
//             in_order(root, q);
    
//             TreeNode *r = NULL;
//             while(!q.empty()){
//                 auto t1 = q.front();
//                 if(!r) r = t1;
//                 q.pop();
//                 t1 -> left = NULL;
    
//                 if(q.empty()) break;
                
//                 auto t2 = q.front();
//                 t1 -> right = t2;
//             }
    
//             return r;
//         }
//     };