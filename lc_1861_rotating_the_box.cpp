#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2024-11-23

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char> > v(n, vector<char>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v[i][j] = box[m - 1 - j][i];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = n - 1; j >= 0; j--){
                if(v[j][i] == '.'){
                    int x = j;
                   for(int k = j - 1; k >= 0; k--) {
                        if(v[k][i] == '#'){
                            swap(v[k][i], v[x][i]);
                            x--;
                        }
                        else if(v[k][i] == '*') break;
                   }
                }
            }
            
        }

        return v;

    }
};