#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

class Solution {
    public:
    
        bool helper(int n, long long int x, int i){
            if(i > 16 || x > n) return false;
            if(n == x) return true;
            
            bool flag = false;
            for(int j = i; j <= 16; j++){
                x += pow(3, j);
                if(x <= n) flag = flag | helper(n, x, j + 1);
                if(x > n) break;
                x -= pow(3, j);
            }
    
            return flag;
        }
    
        bool checkPowersOfThree(int n) {
            long long int x = 0;
    
            return helper(n, x, 0);
        }
    };