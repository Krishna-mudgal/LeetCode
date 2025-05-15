#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-uncommon-subsequence-i/description/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;
        else {
            int x = a.size(), y = b.size();

            if(x < y) return y;
            else return x;
        }
    }
};