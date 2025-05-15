#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-left-leaves/description/

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
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(!root -> left && !root -> right) return 0;
        
//         queue<pair<TreeNode *, TreeNode *> > q;
//         if(root -> left) q.push({root -> left, root});
//         if(root -> right) q.push({root -> right, root});
//         int ans = 0;

//         while(q.size() > 0){
//             int n = q.size();

//             for(int i = 0; i < n; i++){ // in level order traversal first element is always leftest element and if it is a leaf node then add it's sum
//                 auto p = q.front();
//                 q.pop();

//                 if((p.second -> left == p.first) && (!p.first -> left && !p.first -> right)) ans += p.first -> val;

//                 if(p.first -> left) q.push({p.first -> left, p.first});
//                 if(p.first -> right) q.push({p.first -> right, p.first});

//             }
//         }
        
//         return ans;

//     }
// };