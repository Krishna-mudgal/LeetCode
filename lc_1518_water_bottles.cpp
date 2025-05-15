#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/water-bottles/description/

class Solution {
public:
    int numWaterBottles(int n, int m) {
        int ans = 0;

        int stock = 0;
        while(n > 0){
            ans += n;
            n += stock;
            stock = 0;
            if(n % m == 0) n /= m;
            else {
                stock += n % m;
                n /= m;
            }
        }

        return ans;
    }
};