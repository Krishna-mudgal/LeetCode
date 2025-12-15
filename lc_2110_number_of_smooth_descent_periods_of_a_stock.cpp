#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/?envType=daily-question&envId=2025-12-15

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int i = 0, j = 1;
        long long ans = 1;
        while(j < n) {
            ans++; // adding single ele present at idx j
            if(prices[j - 1] == prices[j] + 1) {
                ans += j - i;
            } else i = j;

            j++;
        }

        return ans;
    }
};