#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& check, int a, int b, int &m, int &n){
        if(a >= m || a < 0 || b < 0 || b >= n || !check[a][b]) return;

        check[a][b] = false;

        if(a + 1 < m && check[a + 1][b] && board[a + 1][b] == 'O') dfs(board, check, a + 1, b, m, n);
        if(a - 1 > 0 && check[a - 1][b] && board[a - 1][b] == 'O') dfs(board, check, a - 1, b, m, n);
        if(a > 0 && b + 1 < n && check[a][b + 1] && board[a][b + 1] == 'O') dfs(board, check, a, b + 1, m, n);
        if(a > 0 && b - 1 > 0 && check[a][b - 1] && board[a][b - 1] == 'O') dfs(board, check, a, b - 1, m, n);

    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        // agr O boundary se connected h to usse connected sare zero ko ham convert ni krskte aur baki remaining jitne bhi zero hai unko convert kr skte hai

        vector<vector<bool> > check(m, vector<bool> (n, true));

        for(int i = 0; i < n; i++){ // checking Os that are present at boundary(0th row and m - 1th row) and marking that chain of Os as false including O at that particular row

            if(board[0][i] == 'O' && check[0][i]) dfs(board, check, 0, i, m, n);
            if(board[m - 1][i] == 'O' && check[m - 1][i]) dfs(board, check, m - 1, i, m, n);

        }

        for(int i = 0; i < m; i++){
            // checking Os that are present at boundary(0th coloum and n - 1th coloum) and marking that chain of Os as false including O at that particular coloum

            if(board[i][0] == 'O' && check[i][0]) dfs(board, check, i, 0, m, n);
            if(board[i][n - 1] == 'O' && check[i][n - 1]) dfs(board, check, i, n - 1, m, n);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && check[i][j]) board[i][j] = 'X';
            }
        }

    }
};