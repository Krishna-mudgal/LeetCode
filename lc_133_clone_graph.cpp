#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution { 
//     public:
//         unordered_map<int, Node *> m;
//         unordered_set<int> st;
//         Node* cloneGraph(Node* node) {
//             if(!node || st.find(node -> val) != st.end()) return NULL;
    
//             Node *r;
//             if(m.find(node -> val) != m.end()){
//                 r = m[node -> val];
//             }
//             else {
//                 r = new Node(node -> val);
//                 m[r -> val] = r;
//             }
    
//             st.insert(r -> val);
    
//             for(int i = 0; i < node -> neighbors.size(); i++){
//                 if(m.find(node -> neighbors[i] -> val) == m.end()){
//                     Node *t = new Node(node -> neighbors[i] -> val);
//                     r -> neighbors.push_back(t);
//                     m[t -> val] = t;
//                 }
//                 else {
//                     r -> neighbors.push_back(m[node -> neighbors[i] -> val]);
//                 }
    
//                 cloneGraph(node -> neighbors[i]);
//             }
    
//             return r;
//         }
//     };