#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/battleships-in-a-board/description/

class Solution {
public:
    
    void helper(vector<vector<char>> &board, int i, int j,  vector<vector<bool>> &visited){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] == '.') return;

        if(board[i][j] == 'X'){
            board[i][j] = '.';
            visited[i][j] = true;
        }

        helper(board, i + 1, j, visited);
        helper(board, i - 1, j, visited);
        helper(board, i, j - 1, visited);
        helper(board, i, j + 1, visited);
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    visited[i][j] = true;
                    helper(board, i + 1, j, visited);
                    helper(board, i - 1, j, visited);
                    helper(board, i, j - 1, visited);
                    helper(board, i, j + 1, visited);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    ans++;
                }
            }
        }

        return ans;
    }
};