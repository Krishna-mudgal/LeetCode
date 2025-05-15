#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

// class Solution { // approach - 1 with O(n) s.c.
// public:
//     void travel(TreeNode *r, unordered_map<int, int> &m){
//         if(r == NULL) return;
        
//         m[r -> val]++;

//         travel(r -> left, m);
//         travel(r -> right, m);

//     }

//     vector<int> findMode(TreeNode* root) {
//         unordered_map<int, int> m;
//         travel(root, m);

//         vector<int> ans;
        
//         int mx_freq = 0;
//         for(auto p : m){
//             if(p.second > mx_freq) {
//                 ans.clear();
//                 ans.push_back(p.first);
//                 mx_freq = p.second;
//             }
//             else if(p.second == mx_freq) ans.push_back(p.first);
//         }

//         return ans;
//     }
// };

// class Solution { // approach 2 with O(1) space complexity
// public:
//     void travel(TreeNode *r, int &curr_num, int &curr_freq, int &mx_freq, vector<int> &ans){
//         if(r == NULL) return;

//         travel(r -> left, curr_num, curr_freq, mx_freq, ans);

//         if(curr_num == r -> val){
//             curr_freq++;
//         }
//         else {
//             curr_num = r -> val;
//             curr_freq = 1;
//         }

//         if(curr_freq > mx_freq) {
//             ans.clear();
//             ans.push_back(r -> val);
//             mx_freq = curr_freq;
//         }
//         else if(mx_freq == curr_freq) ans.push_back(r -> val);

//         travel(r -> right, curr_num, curr_freq, mx_freq, ans);
    

//     }

//     vector<int> findMode(TreeNode* root) {
//         int mx_freq = 0;
//         int curr_freq = 0;
//         int curr_num = root -> val;
//         vector<int> ans;
//         travel(root, curr_num, curr_freq, mx_freq, ans);

//         return ans;
//     }
// };