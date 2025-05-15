#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/recover-binary-search-tree/

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
// class Solution { // space : O(n)
// public:
//     void inorder(TreeNode *r, vector<int> &arr){
//         if(r == NULL) return;

//         inorder(r -> left, arr);
//         arr.push_back(r -> val);
//         inorder(r -> right, arr);
//     }
//     void inorder_2(TreeNode *r, vector<int> &arr, int &idx){
//         if(r == NULL) return;

//         inorder_2(r -> left, arr, idx);
//         r -> val = arr[idx];
//         idx++;
//         inorder_2(r -> right, arr, idx);
//     }
//     void recoverTree(TreeNode* root) {
//         vector<int> arr;
//         inorder(root, arr);

//         sort(arr.begin(), arr.end());

//         int idx = 0;
//         inorder_2(root, arr, idx);
        
//     }
// };

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
// class Solution { // space : O(1)
// public:
//     void inorder(TreeNode *r, TreeNode *&first, TreeNode *&middle ,TreeNode *&second, TreeNode *&prev){
//         if(r == NULL) return;

//         inorder(r -> left, first, middle, second, prev);
//         if(prev && prev -> val > r -> val) {
//             cout << prev -> val << " " << r -> val << endl; 
//             if(first == NULL){
//                 first = prev;
//                 middle = r;
//             }
//             else second = r;
//         }

//         prev = r;
//         inorder(r -> right, first, middle, second, prev);

//     }
//     void recoverTree(TreeNode* root) {
//         TreeNode *first = NULL, *second = NULL, *middle = NULL, *prev = NULL;

//         inorder(root, first, middle,second, prev);

//         if(second) swap(first -> val , second -> val); // case - when two nodes not adjacent are swaped
//         else swap(first -> val, middle -> val); // case - when two adjacent nodes are swaped

//     }   
// };