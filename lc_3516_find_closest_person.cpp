#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-closest-person/description/?envType=daily-question&envId=2025-09-04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        return (abs(y - z) < abs(x - z) ) ? 2 : ((abs(y - z) == abs(x - z)) ? 0 : 1);
    }
};