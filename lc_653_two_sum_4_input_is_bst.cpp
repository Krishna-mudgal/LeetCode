#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
// class Solution { // approach - 1
// public:
//     bool helper(TreeNode *r, int &k, unordered_map<int, int> &m){
//         if(r == NULL) return false;

//         int rem = k - r -> val;
//         if(m.find(rem) != m.end()) return true;
//         else m[r -> val]++;

//         return helper(r -> left, k, m) || helper(r -> right, k, m);

//     }
//     bool findTarget(TreeNode* root, int k) {
//         unordered_map<int, int> m;
//         return helper(root, k, m);
//     }
// };

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution { // approach - 2
// public:
//     void helper(TreeNode *r, vector<int> &v){
//         if(r == NULL) return;

//         helper(r -> left, v);
//         v.push_back(r -> val);
//         helper(r -> right, v);

//     }
//     bool findTarget(TreeNode* root, int k) { 
//         vector<int> v;

//         helper(root, v);

//         int l = 0, r = v.size() - 1;

//         while(l < r){
//             if(v[l] + v[r] == k) return true;
//             else if(v[l] + v[r] > k) r--;
//             else l++;
//         }

//         return false;
        
//     }
// };