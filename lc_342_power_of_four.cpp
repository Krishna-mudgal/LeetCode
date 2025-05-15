#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0 || (n > 1 && n < 4)) return false;

        if(n == 1) return true;

        while(n > 4){
            if(n % 4 != 0) return false;
            n /= 4;
        }

        if(n == 4) return true;
        else return false;

    }
};