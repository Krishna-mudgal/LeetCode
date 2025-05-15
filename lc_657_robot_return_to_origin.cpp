#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/robot-return-to-origin/description/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;

        for(char c : moves){
            if(c == 'D') y--;
            else if(c == 'U') y++;
            else if(c == 'L') x--;
            else x++;
        }

        return (x == 0 && y == 0);

    }
};