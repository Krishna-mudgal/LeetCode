#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-frequent-subtree-sum/description/

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

//     int traversal(TreeNode *r) {
//         if(!r) return 0;
//         return r -> val + traversal(r -> left) + traversal(r -> right);
//     }

//     void helper(TreeNode *r, unordered_map<int, int> &mp) {
//         if(!r) return;

//         mp[traversal(r)]++;

//         helper(r -> left, mp);
//         helper(r -> right, mp);
//     }

//     vector<int> findFrequentTreeSum(TreeNode* root) {
//         unordered_map<int, int> mp;
//         helper(root, mp);

//         int freq = 0;
//         vector<int> ans;

//         for(auto p : mp) {
//             if(p.second > freq) {
//                 ans.clear();
//                 ans.push_back(p.first);
//                 freq = p.second;
//             } else if(p.second == freq) ans.push_back(p.first);
//         }

//         return ans;
//     }
// };