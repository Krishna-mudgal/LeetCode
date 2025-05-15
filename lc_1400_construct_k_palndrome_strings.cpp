#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-k-palindrome-strings/description/

class Solution { // done using hints only
public:
    bool canConstruct(string s, int k) { 
        int n = s.size();
        if(n < k) return false;

        unordered_map<char, int> m;

        for(auto c : s) m[c]++;

        int x = 0;
        for(auto p : m){
            if(p.second % 2 != 0) x++;
        }

        return x <= k;

    }
};