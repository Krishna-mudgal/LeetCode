#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
//     public:
//         void helper(TreeNode *r, unordered_map<TreeNode *, TreeNode *> &m){
//             if(!r) return;
    
//             if(r -> left) m[r -> left] = r;
//             if(r -> right) m[r -> right] = r;
    
//             helper(r -> left, m);
//             helper(r -> right, m);
    
//         }
    
//         void helper_2(unordered_map<TreeNode *, TreeNode *> &parent, vector<int> &ans, TreeNode *r, int dist, int &k, unordered_set<TreeNode *> &st){
//             if(!r) return;
//             if(dist == k){
//                 ans.push_back(r -> val);
//                 return;
//             }
    
//             st.insert(r);
    
//             if(st.find(r -> left) == st.end()) helper_2(parent, ans, r -> left, dist + 1, k, st);
//             if(st.find(r -> right) == st.end()) helper_2(parent, ans, r -> right, dist + 1, k, st);
//             if(st.find(parent[r]) == st.end()) helper_2(parent, ans, parent[r], dist + 1, k, st);
    
//         }
    
//         vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//             vector<int> ans;
//             unordered_map<TreeNode*, TreeNode *> parent;
//             unordered_set<TreeNode *> st;
//             helper(root, parent);
//             helper_2(parent, ans, target, 0, k, st);
    
//             return ans;
//         }
//     };