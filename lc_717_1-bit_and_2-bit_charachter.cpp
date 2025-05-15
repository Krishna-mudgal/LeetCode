#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/1-bit-and-2-bit-characters/description/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return true;

        int i = 0;
        while(i < n){
            if(bits[i] == 1) {
                i += 2;
            }
            else i++;

            if(i == n - 2 && bits[i] == 1) return false;
            else if(i == n - 2 && bits[i] == 0) return true;
            if(i == n - 1) return true;
        }
        
        if(i == n) return false;

        return true;

    }
};