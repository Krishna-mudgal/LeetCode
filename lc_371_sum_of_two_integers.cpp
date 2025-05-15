#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
public:
    int getSum(int a, int b) {
        return a + b;
    }
};

class Solution { // gives run time error
public:
    int getSum(int a, int b) {
        return log(exp(a)*exp(b));
    }
};