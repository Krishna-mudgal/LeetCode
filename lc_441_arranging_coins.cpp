#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/arranging-coins/description/

class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        long long int x = (long long int)n;
        int hi = sqrt(2*x);
        int lo = 1;
        int ans = 0;

        while(lo <= hi){
            long long int mid = lo + (hi - lo)/2;

            if((mid * (mid + 1))/2 == x) return mid;
            else if((mid * (mid + 1))/2 < x){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;

    }
};