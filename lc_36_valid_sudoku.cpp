#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-sudoku/?envType=daily-question&envId=2025-08-30

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { // O(1) since board is always 9*9 but if it is variable then T.C. = O(n^2)
        int r_s = 0, r_e = 2, c_s = 0, c_e = 2;
        vector<unordered_set<int>> col(9);
        vector<unordered_set<int>> row(9);
        for(int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for(int j = r_s; j <= r_e; j++) {
                for(int k = c_s; k <= c_e; k++) {
                    if(board[j][k] == '.') continue;

                    if(st.find(board[j][k]) != st.end()) {
                        return false;
                    } 

                    if(row[j].find(board[j][k]) != row[j].end()) return false;
                    if(col[k].find(board[j][k]) != col[k].end()) return false;

                    st.insert(board[j][k]);
                    row[j].insert(board[j][k]);
                    col[k].insert(board[j][k]);
                }
            }

            if(c_e < 8) {
                c_s += 3;
                c_e += 3;
            } else {
                r_s += 3;
                r_e += 3;
                c_s = 0;
                c_e = 2;
            }
        }



        return true;
    }
};