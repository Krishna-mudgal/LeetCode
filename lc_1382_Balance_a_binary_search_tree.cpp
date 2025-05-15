#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/balance-a-binary-search-tree/description/

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

//         if(r -> left) travel(r -> left, v);

//         v.push_back(r -> val);

//         if(r -> right) travel(r -> right, v);
//     }

//     TreeNode *solve(vector<int> &v, int lo, int hi){
//         if(hi < lo) return NULL;
//         // balance tree ke liye middle ko hi root bnana pdega
        
//         int mid = lo + (hi - lo)/2;
//         TreeNode *t = new TreeNode(v[mid]);

//         // since array is sorted to mid ke left m sab value v[mid] se small hi hoge to wo lst hojyga
//         t -> left = solve(v, lo, mid - 1);

//         // since array is sorted to mid ke right m sab value v[mid] se large hi hoge to wo rst hojyga
//         t -> right = solve(v, mid + 1, hi);

//         return t;
//     }

//     TreeNode* balanceBST(TreeNode* root) {
//         vector<int> v;
//         travel(root, v);
//         int n = v.size();
//         return solve(v, 0, n - 1);
//     }
// };