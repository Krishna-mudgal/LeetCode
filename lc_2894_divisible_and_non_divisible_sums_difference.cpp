#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-question&envId=2025-05-27

class Solution { // T.C. = O(n)
public:
    int differenceOfSums(int n, int m) {
        int num2 = 0;
        long long total_sum = (n * (n + 1))/2;
        for(int i = m; i <= n; i++){
            if(i % m == 0) num2 += i;
        }
        
        int num1 = total_sum - num2;

        return num1 - num2;

    }
};

class Solution { // More optimized
public:
    int differenceOfSums(int n, int m) {
        int num2 = 0;
        long long total_sum = (n * (n + 1))/2;
        int i = 1;
        while(i * m <= n){
            num2 += (i * m);
            i++;
        }
        int num1 = total_sum - num2;

        return num1 - num2;

    }
};