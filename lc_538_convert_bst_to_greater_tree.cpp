#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/convert-bst-to-greater-tree/description/

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
//     void travel(TreeNode *r, vector<int> &v){
//         if(!r) return;

//         travel(r -> left, v);
//         v.push_back(r -> val);
//         travel(r -> right, v);
//     }
    
//     void travel(TreeNode *r, vector<int> &v, int &idx){
//         if(!r) return;
        
//         travel(r -> left, v, idx);
//         r -> val = v[idx];
//         idx++;
//         travel(r -> right, v, idx);

//     }

//     TreeNode* convertBST(TreeNode* r) {
//         if(!r) return r;

//         vector<int> v;
//         travel(r, v);

//         int n = v.size();

//         for(int i = n - 2; i >= 0; i--){
//             v[i] += v[i + 1];
//         }

//         int idx = 0;

//         travel(r, v, idx);

//         return r;
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
// class Solution { // optimized
// public:
    
//     void travel(TreeNode *r, int &sum){
//         if(!r) return ;

//         travel(r -> right, sum);
//         sum += r -> val;
//         r -> val = sum;
//         travel(r -> left, sum);
//     }

//     TreeNode* convertBST(TreeNode* root) {
//         int sum = 0;
//         travel(root, sum);

//         return root;
//     }
// };