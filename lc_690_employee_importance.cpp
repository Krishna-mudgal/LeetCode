#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/employee-importance/description/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// class Solution {
// public:
    
//     int add(vector<int> v, unordered_map<int, int> &m1, unordered_map<int, vector<int>> &m2){
//         if(v.size() == 0) return 0;
//         int ans = 0;
//         for(int i : v){
//             ans += m1[i];
//             ans += add(m2[i], m1, m2);
//         }

//         return ans;
//     }

//     int getImportance(vector<Employee*> employees, int id) {
//         unordered_map<int, int>m1;
//         unordered_map<int, vector<int>>m2;
//         for(auto e : employees){
//             m1[e -> id] = e -> importance;
//             if(e -> subordinates.size() > 0) m2[e -> id] = e -> subordinates;
//         }

//         int ans = 0;
//         for(auto e : employees){
//             if(e -> id == id){
//                 ans += e -> importance;
//                 ans += add(e -> subordinates, m1, m2);
//             }
//         }

//         return ans;
//     }
// };

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// class Solution { // more clear than previous
// public:
//     int getImportance(vector<Employee*> employees, int id) {
        
//         unordered_map<int, Employee*> m;
//         queue<int> q;

//         for(auto e : employees){
//             m[e -> id] = e;
//             if(e -> id == id) q.push(e -> id);
//         }

//         int ans = 0;
//         while(!q.empty()){
//             int i = q.front();
//             q.pop();
//             auto e = m[i];
//             ans += e -> importance;
//             for(int j : e -> subordinates) q.push(j);
//         }

//         return ans;

//     }
// };