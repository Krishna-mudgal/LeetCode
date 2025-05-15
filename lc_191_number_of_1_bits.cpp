#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> bs(n); // converts number into binary
        
        int ans = 0;
        for(int i = 0; i < bs.size(); i++){
            if(bs[i] == 1) ans++;
        }

        return ans;
    }
};