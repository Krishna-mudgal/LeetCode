#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <=right; i++){
            int x = __builtin_popcount(i);
            if(x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19) ans++;
        }

        return ans;
    }
};