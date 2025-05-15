#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2024-10-19

class Solution {
public:
    
    string invert(string s){
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') ans += '1';
            else ans += '0';
        }

        return ans;
    }

    char findKthBit(int n, int k) {
        vector<string> v(n);
        v[0] = "0";

        for(int i = 1; i < n; i++){
            string x = invert(v[i - 1]);
            reverse(x.begin(), x.end());
            v[i] = v[i - 1] + "1" + x;
        }

        string x = v[n - 1];

        return x[k - 1];
    }
};