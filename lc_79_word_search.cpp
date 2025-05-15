#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool helper(vector<vector<char> > &board, string &s, int i, int j, int idx, int &m, int &n, vector<vector<bool> > &used){
        if(idx == s.size() - 1) return true;
        if(i >= m || j >= n) return false;

        if(i > 0 && !used[i - 1][j] && board[i - 1][j] == s[idx + 1]) {
            used[i - 1][j] = true;
            bool ans = helper(board, s, i - 1, j, idx + 1, m, n, used);
            if(ans) return true;
            else used[i - 1][j] = false; // backtracking
        }
        if(i < m - 1 && !used[i + 1][j] && board[i + 1][j] == s[idx + 1]) {
            used[i + 1][j] = true;
            bool ans = helper(board, s, i + 1, j, idx + 1, m, n, used);
            if(ans) return true;
            else used[i + 1][j] = false; // backtracking
        }
        if(j > 0 && !used[i][j - 1] && board[i][j - 1] == s[idx + 1]) {
            used[i][j - 1] = true;
            bool ans = helper(board, s, i, j - 1, idx + 1, m, n, used);
            if(ans) return true;
            else used[i][j - 1] = false; // backtracking
        }
        if(j < n - 1 && !used[i][j + 1] && board[i][j + 1] == s[idx + 1]) {
            used[i][j + 1] = true;
            bool ans = helper(board, s, i, j + 1, idx + 1, m, n, used);
            if(ans) return true;
            else used[i][j + 1] = false; // backtracking
        } 
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > used(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    used[i][j] = true;
                    if(word.size() == 1) return true;
                    bool ans = false;
                    if(j < n - 1 && board[i][j + 1] == word[1]) {
                        used[i][j + 1] = true;
                        ans = helper(board, word, i, j + 1, 1, m, n, used);
                        if(ans) return true;
                        else used[i][j + 1] = false;
                    }
                    if(i < m - 1 && board[i + 1][j] == word[1]) {
                        used[i + 1][j] = true;
                        ans = helper(board, word, i + 1, j, 1, m, n, used);
                        if(ans) return true;
                        else used[i + 1][j] = false;
                    }
                    if(i > 0 && board[i - 1][j] == word[1]){
                        used[i - 1][j] = true;
                        ans = helper(board, word, i - 1, j, 1, m, n, used);
                        if(ans) return true;
                        else used[i - 1][j] = false;
                    }
                    if(j > 0 && board[i][j - 1] == word[1]) {
                        used[i][j - 1] = true;
                        ans = helper(board, word, i, j - 1, 1, m, n, used);
                        if(ans) return true;
                        else used[i][j - 1] = false;
                    }
                    used[i][j] = !used[i][j]; // backtracking
                }
            }
        }

        return false;

    }
};