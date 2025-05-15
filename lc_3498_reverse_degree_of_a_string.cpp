#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverseDegree(string s) {
            int n = s.size();
            int ans = 0;
            for(int i = 0; i < n; i++){
                int x = 26 - (s[i] - 'a');
                // cout << x << endl;
                ans += x*(i + 1);
            }
    
            return ans;
        }
    };