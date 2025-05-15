#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/nim-game/description/

class Solution {
public:
    bool canWinNim(int n) {
        // if(n <= 3)  return true; // this is a winning state

        // if(n == 4 || n == 8) return false; // 4 and 8 are loosing states

        // return !(canWinNim(n - 1) && canWinNim(n - 2) && canWinNim(n - 3)); // khi pr se bhi mai ydi dusre wale ko lossing state pr phucha du to wo mere liye winning state hai

        return !(n % 4 == 0);

    }
};