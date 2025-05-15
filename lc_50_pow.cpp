#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0000;

        if(x == 1 || x == 0) return x;
        else if(x == -1){
            if(n % 2 == 0) return -x;
            else return x;
        }

        double ans = 1.0000;
        int y = n;
        bool flag = false;
        
        if(n < 0){
            if(n == -2147483648){
                n = INT_MAX;
                flag = false;
            }
            else  n = -n;
        }
        int a = abs(y/2);

        while(n > a){
            ans *= x;
            n--;
        }
        if(y % 2 == 0) ans *= ans;
        else {
            ans *= (ans/x);
        }
        
        if(y < 0){
            if(flag) return 1/(ans*x);
            else return 1/(ans);
        }
        else return ans;
        
    }
};

// second approach

class Solution {
public:
    double helper(double x, int n){
        if(x == 0 || x == 1) return x;
        if(n == 0) return 1;
        if(x == -1){
            if(n % 2 == 0) return 1;
            else return -1;
        }
        if(n % 2 == 0) return helper(x*x, n/2);
        else return x * helper(x, n - 1);
    }
    double myPow(double x, int n) {
        if(x == 0 || x == 1) return x;
        if(n == 0) return 1;
        if(x == -1){
            if(n % 2 == 0) return 1;
            else return -1;
        }
        if(n == INT_MIN) return 1/myPow(x*x, -1 - (n/2));
        if(n < 0) return 1/(helper(x, -n));
        else return helper(x, n);
    }
};