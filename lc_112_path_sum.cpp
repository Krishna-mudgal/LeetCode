#include <bits/stdc++.h>
using namespace std;

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

// https://leetcode.com/problems/path-sum/description/

class Solution {
public:
    bool helper(TreeNode *r, int sum, int tar){
        if(r == NULL) return false;

        if(!(r -> left) && !(r -> right)){ // if leaf node then check sum + r -> val = target if yes then return true else false
            if(sum + r -> val == tar) return true;
            else return false;
        }

        return helper(r -> left, sum + r -> val, tar) || helper(r -> right, sum + r -> val, tar); // means if any one of them is true then ture will be returned

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)  return false;
        if(!(root -> left) && !(root -> right)){
            if(root -> val == targetSum) return true;
            else return false;
        }

        return helper(root, 0, targetSum);
    }
};