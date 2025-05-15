#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-digits/description/

class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int x = num;
            num = 0;
            while(x > 0){
                int last = x%10;
                x /= 10;
                num += last;
            }
        }

        return num;
    }
};

// one more approach

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;

        if(num % 9 == 0) return 9;
        else return num%9;
    }
};