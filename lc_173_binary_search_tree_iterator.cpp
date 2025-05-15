#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-search-tree-iterator/description/

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
// class BSTIterator {
//     public:
//         vector<int> v;
//         int idx = 0;
    
//         void in_order(TreeNode *r){
//             if(!r) return;
    
//             in_order(r -> left);
//             v.push_back(r -> val);
//             in_order(r -> right);
//         }
    
//         BSTIterator(TreeNode* root) {
//             in_order(root); // T.C. = O(n)
//         }
        
//         int next() { // T.C. = O(1)
//             return v[idx++];
//         }
        
//         bool hasNext() { // T.C. = O(1)
//             return idx < v.size();
//         }
//     };
    
//     /**
//      * Your BSTIterator object will be instantiated and called as such:
//      * BSTIterator* obj = new BSTIterator(root);
//      * int param_1 = obj->next();
//      * bool param_2 = obj->hasNext();
//      */