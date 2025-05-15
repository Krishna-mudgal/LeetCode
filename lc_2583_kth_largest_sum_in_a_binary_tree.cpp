#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22

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
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         vector<long long> v;

//         queue<TreeNode *> q;
//         q.push(root);

//         while(!q.empty()){
//             int n = q.size();
//             long long sum = 0;

//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 sum += t -> val;

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }

//             v.push_back(sum);
//         }

//         sort(v.begin(), v.end());

//         return (v.size() >= k) ? v[v.size() - k] : -1;
//     }
// };