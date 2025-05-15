#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-product-of-two-digits/description/

class Solution {
    public:
        int maxProduct(int n) {
            int maxi = INT_MIN, sec_maxi = INT_MIN;
    
            while(n > 0){
                int y = n % 10;
                n /= 10;
    
                if(maxi < y) {
                    sec_maxi = maxi;
                    maxi = y;
                }
                else if(sec_maxi < y) sec_maxi = y;
            }
    
            return maxi*sec_maxi;
        }
    };