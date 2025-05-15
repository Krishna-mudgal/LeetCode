#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-gap/description/

class Solution {
    public:
        int binaryGap(int n) {
            auto b = bitset<32> (n);
            string s = b.to_string();
            
            int ans = 0;
            int i = 0, j = 0, m = s.size();
            while(i < m && j < m){
                if(s[i] == '0') i++;
                else {
                    j = i + 1;
                    while(j < m && s[j] == '0') j++;
                    if(j < m) ans = max(ans, j - i);
                    i = j;
                }
            }
    
            return ans;
        }
    };