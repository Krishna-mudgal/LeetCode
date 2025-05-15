#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-of-matches-in-tournament/description/

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        int x;
        while(n > 1){
            if(n % 2 == 0) x = n/2;
            else x = (n - 1)/2;

            ans += x;
            n -= x;
        }

        return ans;
    }
};