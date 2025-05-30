#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0 || n < 0) return false;
        while(n > 1){
            if(n % 2 != 0) return false;
            n = (n >> 1);
        }
        return true;
    }
};