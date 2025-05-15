#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/?envType=daily-question&envId=2024-12-23
// T.C. = O(nlogn)

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
//     int minimumOperations(TreeNode* root) {
//         int ans = 0;
//         queue<TreeNode *> q;
//         q.push(root);

//         vector<int> v, v2;
//         unordered_map<int, int> m;
//         while(!q.empty()){
//             int n = q.size();
//             v.resize(0);
//             for(int i = 0; i < n; i++){
//                 auto t = q.front();
//                 q.pop();

//                 v.push_back(t -> val);

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }
//             v2 = v;
//             sort(v2.begin(), v2.end());
//             m.clear();
//             for(int i = 0; i < n; i++){
//                 m[v2[i]] = i;
//             }
//             int i = 0;
//             while(i < n){
//                 if(m[v[i]] == i) i++;
//                 else {
//                     swap(v[i], v[m[v[i]]]);
//                     ans++;
//                 }
//             }
//         }

//         return ans;
//     }
// };