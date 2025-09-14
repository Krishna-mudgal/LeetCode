#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-string-from-binary-tree/description/

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

class TreeNode {
public :
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val = 0){
        this -> val = val;
        this ->left = nullptr;
        this -> right = nullptr;
    }

    TreeNode(int val = 0, TreeNode* left, TreeNode *right){
        this -> val = val;
        this ->left = left;
        this -> right = right;
    }
};

class Solution {
public:

    string solve(TreeNode *r) {
        if(!r) return "";

        if(!r -> left && !r -> right) return to_string(r -> val);
        else if(!r -> left && r -> right) return to_string(r -> val) + "()" + "(" + solve(r -> right) + ")";
        else if(r -> left && !r -> right) return to_string(r -> val) + "(" + solve(r -> left) + ")";
        else return to_string(r -> val) + "(" + solve(r -> left) + ")" + "(" + solve(r -> right) + ")";
    }

    string tree2str(TreeNode* root) {
       if(!root) return "";
        return solve(root);
    }
};