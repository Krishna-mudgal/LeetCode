#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int x = (n % 2 == 0) ? 1 : 0;
        while(x <= n/2) {
            ans.push_back(x);
            if(x != 0) ans.push_back(-x);

            x++;
        }

        return ans;
    }
};