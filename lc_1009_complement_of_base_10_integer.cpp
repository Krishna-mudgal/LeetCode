#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n == 0) return 1;

        bitset<30> b(n);
        bitset<30> ans;

        bool flag = true;
        for(int i = 30; i >= 0; i--){
            if(b[i] == 1) flag = false;
            if(!flag){
                if(b[i] == 0) ans[i] = 1;
                else ans[i] = 0;
            }
        }

        // cout << b << endl << ans;

        return ans.to_ulong();
    }
};