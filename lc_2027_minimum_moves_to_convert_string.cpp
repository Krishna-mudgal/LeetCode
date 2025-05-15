#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-moves-to-convert-string/description/

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();

        int ans = 0;
        for(int i = 0; i <= n - 3; i++){
            bool flag = false;
            if(s[i] == 'O' && i != n - 3) continue;
            for(int j = i; j < i + 3; j++){
                if(s[j] == 'X') {
                    flag = true;
                    s[j] = 'O';
                }
            }
            if(flag) ans++;
        }

        return ans;
    }   
};