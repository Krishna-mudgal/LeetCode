#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/hash-divided-string/description/

class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();

        string ans = "";

        int i = 0;
        while(i < n){
            int x = 0;
            for(int j = 0; j < k; j++){ // finding sum of hash values
                x += (s[i] - 'a');
                i++;
            }
            x = x % 26; // finding hashedChar
            ans += (char)(x + 'a');
        }

        return ans;

    }
};