#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        vector<pair<int, int> > v1, v2; // v2 to contains index which are needed to be converted into 0 and v1 contain those index which are needed to be converted into 1

        for(int i = 0; i < m; i++){
            for(int  j = 0; j < n; j++){
                int live = 0;

                if(i - 1 >= 0 && board[i - 1][j] == 1) live++;
                if(i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1) live++;
                if(i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] == 1) live++;
                if(j + 1 < n && board[i][j + 1] == 1) live++;

                if(live > 3) {
                    v2.push_back({i, j});
                    continue;
                }

                if(j - 1 >= 0 && board[i][j - 1] == 1) live++;

                if(live > 3) {
                    v2.push_back({i, j});
                    continue;
                }

                if(i + 1 < m && j + 1 < n && board[i + 1][j + 1] == 1) live++;
                if(live > 3) {
                    v2.push_back({i, j});
                    continue;
                }

                if(i + 1 < m && j - 1 >= 0 && board[i + 1][j - 1] == 1) live++;
                if(live > 3) {
                    v2.push_back({i, j});
                    continue;
                }

                if(i + 1 < m && board[i + 1][j] == 1) live++;

                // cout << i << " " << j << " " << live << endl;

                if(live < 2 || live > 3) v2.push_back({i, j});
                else if(live == 3) v1.push_back({i, j});
            }
        }

        for(int i = 0; i < v2.size(); i++) board[v2[i].first][v2[i].second] = 0;

        for(int i = 0; i < v1.size(); i++) board[v1[i].first][v1[i].second] = 1;

    }
};