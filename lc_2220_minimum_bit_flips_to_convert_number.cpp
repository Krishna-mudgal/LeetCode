#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11


class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> b1(start);
        bitset<32> b2(goal);
        int ans = 0;

        for(int i = 0; i < 32; i++){
            if(b1[i] != b2[i]) ans++;
        }
        return ans;
        
    }
};

// approach 2

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;

        return __builtin_popcount(x);
    }
};