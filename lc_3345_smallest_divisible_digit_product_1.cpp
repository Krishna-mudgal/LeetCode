#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/smallest-divisible-digit-product-i/

class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++){
            string x = to_string(i);
            int a = 1;
            for(char c : x){
                a *= (c - '0');
            }
            if(a % t == 0) return i;
        }
        return -1;
    }
};