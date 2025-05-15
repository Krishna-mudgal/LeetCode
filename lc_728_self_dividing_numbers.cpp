#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/self-dividing-numbers/description/

class Solution {
public:

    bool valid(int &x){
        int y = x;
        while(y > 0){
            int last_digit = y % 10;
            y /= 10;
            
            if(last_digit == 0) return false;

            if(x % last_digit != 0) return false;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(valid(i)) ans.push_back(i);
        }

        return ans;
    }
};