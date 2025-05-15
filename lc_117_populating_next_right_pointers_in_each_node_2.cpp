#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
        
//         if(!root) return root;

//         queue<Node *> q;
//         q.push(root);

//         while(q.size() > 0){
//             int n = q.size();

//             for(int i = 0; i < n; i++){
//                 Node *t = q.front();
//                 q.pop();

//                 if(!q.empty() && i < n - 1){
//                     Node *t2 = q.front();
//                     t -> next = t2;
//                 }

//                 if(t -> left) q.push(t -> left);
//                 if(t -> right) q.push(t -> right);
//             }
//         }

//         return root;

//     }
// };