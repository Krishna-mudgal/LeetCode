#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/water-bottles-ii/description/

class Solution {
public:
    int maxBottlesDrunk(int n, int m) {
        int ans = 0;

        while(n >= m) {
            ans += m; // jitne exchange krskte ho water bottle utna hi pani piyo
            n -= m; // m bottle pani pi liya to m bottle empty hogyi
            n++; // ab usko exchange krlo
            m++;
        }

        ans += n;
        return ans;
    }
};