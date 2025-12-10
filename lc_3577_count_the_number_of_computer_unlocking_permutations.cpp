#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/?envType=daily-question&envId=2025-12-10

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        long long MOD = 1000000007;

        long long ans = 1;
        for(int i = 1; i < n; i++) {
            if(complexity[0] >= complexity[i]) return 0;
            
            ans *= i;
            ans %= MOD;
        }

        return ans;
    }
};