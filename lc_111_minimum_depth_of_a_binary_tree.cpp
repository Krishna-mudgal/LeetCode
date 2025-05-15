#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/


class Solution {
public:
    void helper(TreeNode *r, int &ans, int c_lvl){
        if(r == NULL) return ;

        if(!(r -> left) && !(r -> right)){
            ans = min(ans, c_lvl); // if leaf node then check for ans
            return;
        }

        if(r -> left) helper(r -> left, ans, c_lvl + 1); // as we go deeper in a tree lvl increases by 1
        if(r -> right) helper(r -> right, ans, c_lvl + 1);

    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = INT_MAX;

        helper(root, ans, 1);

        return ans;

    }
};