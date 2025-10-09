#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/complete-binary-tree-inserter/description/

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

// class CBTInserter {
// public:
//     TreeNode *r;
//     CBTInserter(TreeNode* root) {
//         r = root;
//         makeCBT(r);
//     }

//     void makeCBT(TreeNode *r) {
//         if(!r) return;

//         if(!r -> left && r -> right) r -> right = NULL;
//         makeCBT(r -> left);
//         makeCBT(r -> right);
//     }

//     int insert(int val) {
//         queue<TreeNode *> q;
//         q.push(r);
        
//         while(!q.empty()) {
//             auto t = q.front();
//             q.pop();

//             if(!t -> left) {
//                 TreeNode *temp = new TreeNode(val);
//                 t -> left = temp;
//                 return t -> val;
//             } else if(!t -> right) {
//                 TreeNode *temp = new TreeNode(val);
//                 t -> right = temp;
//                 return t -> val;
//             }

//             q.push(t -> left);
//             q.push(t -> right);
//         }

//         return -1;
//     }
    
//     TreeNode* get_root() {
//         return r;
//     }
// };

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */