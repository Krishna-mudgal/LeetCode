#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = (x ^ y);
        return __builtin_popcount(a);
    }
};