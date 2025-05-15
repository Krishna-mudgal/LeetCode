#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21

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
// class FindElements {
//     public:
    
//         unordered_set<int> st;
//         void helper(TreeNode *r){
//             if(!r) return;
            
//             st.insert(r -> val);
    
//             if(r -> left) {
//                 r -> left -> val = 2*(r -> val) + 1;
//                 helper(r -> left);
//             }
//             if(r -> right) {
//                 r -> right -> val = 2*(r -> val) + 2;
//                 helper(r -> right);
//             }
//         }
    
//         FindElements(TreeNode* root) {
//             root -> val = 0;
    
//             if(root -> left) root -> left -> val = 1;
//             if(root -> right) root -> right -> val = 2;
    
//             st.insert(0);
    
//             helper(root -> left);
//             helper(root -> right);
//         }
        
//         bool find(int target) {
//             return st.find(target) != st.end();
//         }
//     };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */