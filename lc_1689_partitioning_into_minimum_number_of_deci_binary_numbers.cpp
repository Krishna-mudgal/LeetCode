#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

class Solution {
    public:
        int minPartitions(string n) {
            char c = 0;
            for(char i : n){
                if(c < i) c = i;
            }
    
            return c - '0';
        }
    };