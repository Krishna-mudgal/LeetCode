#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/?envType=daily-question&envId=2024-11-07

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();

        int ans = 0;
        for(int i = 0; i <= 24; i++){
            int x = 0;
            // jitne candidates[j] m ith bit pr 1 h to wo combination m include krege

            // agr ith bit 1 h candidate[j] ki to x++ krdo denoting usko us particular combination m add krliya hai
            for(int j = 0; j < n; j++){
                int y = i;
                int ith_bit = 0;
                int c = candidates[j];
                while(y > 0){
                    ith_bit = c & 1; // c & 1 is same as c % 2
                    c = c >> 1; // c >> 1 is same as c/2
                    y--;
                }
                if(ith_bit == 1) x++;
            }
            ans = max(ans, x);
        }

        return ans;

    }
};