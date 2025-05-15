#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cousins-in-binary-tree/description/

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
//     bool isCousins(TreeNode* root, int x, int y) {
//         queue<pair<TreeNode *, TreeNode *>> q;
//         if(root -> left) q.push({root, root -> left});
//         if(root -> right) q.push({root, root -> right});
        
//         TreeNode *p1 = NULL, *p2 = NULL;
//         while(!q.empty()){
//             int n = q.size();

//             bool f1 = false;
//             bool f2 = false;
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 if(t.second -> val == x){
//                     f1 = true;
//                     p1 = t.first;
//                 }
//                 if(t.second -> val == y){
//                     f2 = true;
//                     p2 = t.first;
//                 }

//                 if(t.second -> left) q.push({t.second, t.second -> left});
//                 if(t.second -> right) q.push({t.second, t.second -> right});

//             }

//             if(f1 && f2) {
//                 return p1 != p2; // parents bhi same hone chiye
//             }
//             if(f1 || f2) return false; // means dono ki depth different hai
//         }

//         return false;

//     }
// };