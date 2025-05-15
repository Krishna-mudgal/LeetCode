#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:
//     void preorder(string &s, TreeNode *r){
//         if(r == NULL) return;

//         s += to_string(r -> val);
//         s += '+';

//         preorder(s, r -> left);
//         preorder(s, r -> right);
//     }
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string s = "";
//         preorder(s, root);
//         return s;
//     }

//     void add(int &x, TreeNode *r){
//         if(!r) return;

//         if(x > r -> val){
//             if(r -> right) add(x, r -> right);
//             else {
//                 TreeNode *t = new TreeNode(x);
//                 r -> right = t;
//             }
//         }
//         else{
//             if(r -> left) add(x, r -> left);
//             else{
//                 TreeNode *t = new TreeNode(x);
//                 r -> left = t;
//             }
//         }

//     }
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == 0) return  NULL;

//         int i = 0;
//         string s = "";
//         while(data[i] != '+'){
//             s += data[i];
//             i++;
//         }
//         cout << s << endl;
//         i++; // skipping '+'

//         TreeNode *root = new TreeNode(stoi(s));
//         while(i < data.size() - 1){
//             string s = "";
//             while(data[i] != '+'){
//                 s += data[i];
//                 i++;
//             }
//             cout << s << endl;
//             i++; // skipping '+'
//             int x;
//             if(s != "" && s != "+") {
//                 x = stoi(s);
//                 add(x, root);
//             }
//         }

//         return root;
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec* ser = new Codec();
// // Codec* deser = new Codec();
// // string tree = ser->serialize(root);
// // TreeNode* ans = deser->deserialize(tree);