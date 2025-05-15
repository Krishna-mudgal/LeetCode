#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-complement/description/

class Solution {
public:
    int findComplement(int num) {
        bitset<32> b(num);
        bitset<32> ans;
        bool flag = true;

        for(int i = 31 ; i >= 0; i--){
            if(b[i] == 1) flag = false;
            if(!flag){
                if(b[i] == 0) ans[i] = 1;
                else if(b[i] == 1) ans[i] = 0;
            }
        }
        
        return ans.to_ulong();
    }
};