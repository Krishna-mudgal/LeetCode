#include <bits/stdc++.h>
using namespace std;


bool cmp(int &a, int &b) {
    return a > b;
}

class Solution { // T.C = O(n^2*log(n))
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v1(n);
        vector<vector<int>> v2(n + 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(j - i  > 0) v1[j - i].push_back(grid[i][j]);
                else v2[abs(j - i)].push_back(grid[i][j]);
            }
        }

        for(auto &diagonal : v1) sort(diagonal.begin(), diagonal.end(), cmp);
        for(auto &diagonal : v2) sort(diagonal.begin(), diagonal.end());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j - i > 0) {
                    grid[i][j] = v1[j - i].back();
                    v1[j - i].pop_back();
                } else {
                    grid[i][j] = v2[abs(j - i)].back();
                    v2[abs(j - i)].pop_back();
                }
            }
        }

        return grid;
    }
};