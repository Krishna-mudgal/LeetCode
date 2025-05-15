#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

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
//         if(root == NULL) return root;

//         queue<Node *> q;
//         q.push(root);

//         while(q.size() > 0){
//             int n = q.size();

//             for(int i = 0; i < n; i++){
//                 Node *temp = q.front();
//                 q.pop();

//                 if(i < n - 1 && !q.empty()){
//                     Node *temp2 = q.front();
//                     temp -> next = temp2;
//                 }

//                 if(temp -> left) q.push(temp -> left);
//                 if(temp -> right) q.push(temp -> right);
//             }
//         }

//         return root;
//     }
// };