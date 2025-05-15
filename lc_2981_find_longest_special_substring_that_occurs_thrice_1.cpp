#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        unordered_map<char, int> m;
        for(auto c : s) m[c]++;

        for(auto p : m){
            char c = p.first;
            int freq = p.second;
            if(freq >= 3){
                string x = "";
                for(int i = 1; i <= freq - 2; i++){
                    x += c;
                    int j = 0, k = x.size() - 1;
                    int freq2 = 0;
                    string y = "";

                    while(k < n){
                        y = "";
                        for(int l = j; l <= k; l++) y += s[l];

                        j++;
                        k++;
                        if(y == x) freq2++;
                    }
                    
                    int z = x.size();
                    if(freq2 >= 3) ans = max(ans, z);
                }
            }
        }

        return ans;
    }
};