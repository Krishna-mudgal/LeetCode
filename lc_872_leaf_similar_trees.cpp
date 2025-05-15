#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/leaf-similar-trees/description/


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
class Solution {
    public:
        void helper(TreeNode *r, string &s){
            if(!r) return ;
    
            if(!r -> left && !r -> right) s += (to_string(r -> val) + '.');
    
            helper(r -> left, s);
            helper(r -> right, s);
        }
    
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            string s1 = "", s2 = "";
    
            helper(root1, s1);
            helper(root2, s2);
    
            return s1 == s2;
        }
    };