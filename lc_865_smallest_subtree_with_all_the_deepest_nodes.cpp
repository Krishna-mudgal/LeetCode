#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        void helper(TreeNode* r, int& x, unordered_set<int>& s) {
            if (!r)
                return;
    
            if (s.find(r->val) != s.end())
                x++;
    
            helper(r->left, x, s);
            helper(r->right, x, s);
        }
    
        void check(TreeNode* r, TreeNode* &ans, unordered_set<int>& s) {
            if (!r)
                return;
    
            int x = 0;
            helper(r, x, s);
    
            if (x == s.size())
                ans = r;
    
            check(r->left, ans, s);
            check(r->right, ans, s);
        }
    
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    
            queue<TreeNode*> q;
            q.push(root);
            unordered_set<int> s;
            // int lvl = 0;
            while (!q.empty()) {
                int n = q.size();
                s.clear();
                for (int i = 0; i < n; i++) {
                    auto t = q.front();
                    q.pop();
                    s.insert(t->val);
    
                    if (t->left)
                        q.push(t->left);
                    if (t->right)
                        q.push(t->right);
                }
            }
    
            TreeNode* ans = root;
            check(root, ans, s);
    
            return ans;
        }
    };