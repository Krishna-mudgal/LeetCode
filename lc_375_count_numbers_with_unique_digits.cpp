#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int solve(int mx, string s, vector<int> &isAllowed) {
        if((!s.empty() && stoi(s) >= mx)) return 0;
        
        int ans = 1;

        for(int i = 0; i <= 9; i++) {
            if(s.size() == 0 && i == 0) continue;
            if(isAllowed[i] == 1) {
                s += (char)(i + '0');
                isAllowed[i] = 0;
                ans += (solve(mx, s, isAllowed)); 
                s.pop_back();
                isAllowed[i] = 1;
            }
        }

        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> isAllowed(10, 1);
        return solve(pow(10, n), "", isAllowed);
    }
};