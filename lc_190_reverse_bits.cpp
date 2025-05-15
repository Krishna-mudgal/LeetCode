#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) { 
        string s = "";

        // while(n > 0){ // doen't work because it can be represented in less bits also
        //     int rem = n % 2;
        //     cout << rem << " ";
        //     n /= 2;
        //     s += to_string(rem);
        // }

        bitset<32> bs(n);
        
        int i = 31;

        long long a = 0, y = 1;
        while(i >= 0){
            a += (bs[i]*y);
            y *= 2;
            i--;
        }


        uint32_t x = static_cast<uint32_t>(a);

        return x;
    }
};