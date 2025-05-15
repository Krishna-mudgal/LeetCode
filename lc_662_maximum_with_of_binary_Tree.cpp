#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    
//     int widthOfBinaryTree(TreeNode* root) {

//         int ans = 1;
//         queue<pair<TreeNode *, long long>> q;
//         q.push({root, 0});

//         while(q.size() > 0){
//             int n = q.size();   
//             long long left_most = q.front().second;
//             long long right_most = q.back().second;

//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();
                
//                 // integer ovrflow a rha tha to normalize krke daalna pdega
//                 long long idx = t.second - left_most;
//                 if(t.first -> left) q.push({t.first -> left, idx*2 + 1});
//                 if(t.first -> right) q.push({t.first -> right, idx*2 + 2});
//             }

//             int x =  right_most - left_most + 1;
//             ans = max(ans, x);
            
//         }

//         return ans;
//     }
// };