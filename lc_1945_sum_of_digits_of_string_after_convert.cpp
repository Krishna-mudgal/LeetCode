#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03s

class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int val = (s[i] - 'a' + 1);
            if(val >= 10) ans += val%10 + val/10;
            else ans += val;
        }
        
        if(k == 1) return ans;

        while(k > 1){
            int z = ans;
            ans = 0;
            while(z > 0){
                int last = z % 10;
                z /= 10;

                ans += last;
            }

            if(ans >= 0 && ans <= 9) return ans;

            k--;
        }

        return ans;

    }
};