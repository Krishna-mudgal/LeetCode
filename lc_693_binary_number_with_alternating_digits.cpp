#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-number-with-alternating-bits/description/

class Solution {
public:
    bool hasAlternatingBits(int n) { // approach - 1
        bitset<32> b(n);

        string s = b.to_string();
        
        int i = 0;
        while(i < s.size() && s[i] != '1') i++;
        
        while(i < s.size() - 1) {
            if(s[i] == s[i + 1]) return false;
            i++;
        }
        

        return true;

    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) { // approach - 2
        int prev = n % 2;
        n /= 2;
        while(n > 0){
            int curr = n % 2;
            n /= 2;

            if(prev ^ curr == 0) return false;

            prev = curr;
        }

        return true;

    }
};