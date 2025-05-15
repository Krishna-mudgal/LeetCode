#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        int sum_rolls = 0;

        for(int i = 0 ; i < m; i++) sum_rolls += rolls[i];

        int sum_ans = (mean*(n + m)) - sum_rolls;

        if(sum_ans > n*6 || sum_ans < n) return {};

        while(n > 1){
            int digit = sum_ans/n ;

            ans.push_back(digit);
            sum_ans -= digit;
            n--;
        }

        ans.push_back(sum_ans);

        return ans;

    }
};