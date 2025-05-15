#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-perfect-square/description/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;

        if(num < 4) return false;

        int i = 2, j = num/2;

        if(j > 46340) j = 46340;

        while(i <= j){
            int mid = i + (j - i)/2;

            if(mid * mid == num) return true;
            else if(mid * mid > num) j = mid - 1;
            else i = mid + 1;
        }

        return false;

    }
};