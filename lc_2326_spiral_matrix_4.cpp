#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// https://leetcode.com/problems/spiral-matrix-iv/?envType=daily-question&envId=2024-09-09

// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//         vector<vector<int>> ans(m, vector<int> (n, -1));
//         int sr = 0, sc = 0, er = m-1, ec = n-1;
//         ListNode *temp = head;
//         while(sr <= er && sc <= ec){
            
//             for(int i=sc; i<=ec; i++) 
//             {   ans[sr][i] = temp -> val;
//                 temp = temp -> next;
//                 if(temp == NULL) return ans;
//             }
//             sr++;
//             if(sr > er || sc > ec) break;

//             for(int i=sr; i<=er; i++){
//                 ans[i][ec] = temp -> val;
//                 temp = temp -> next;
//                 if(temp == NULL) return ans;
//             }
//             ec--;
//             if(sr > er || sc > ec) break;

//             for(int i=ec; i>=sc; i--){
//                 ans[er][i] = temp -> val;
//                 temp = temp -> next;
//                 if(temp == NULL) return ans;
//             }
//             er--;
//             if(sr > er || sc > ec) break;

//             for(int i=er; i>=sr; i--){
//                 ans[i][sc] = temp -> val;
//                 temp = temp -> next;
//                 if(temp == NULL) return ans;
//             }
//             sc++;
//             if(sr > er || sc > ec) break;
//         }
//         return ans;
//     }
// };