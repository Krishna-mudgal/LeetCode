#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
    
            int ans = 0;
            unordered_map<char, int> m;
            int i = 0, j = 0;
            while(j < n){
                while(j < n && m.size() < 3){
                    m[s[j]]++;
                    j++;
                }
    
                if(m.size() == 3){
                    while(i < j && m.size() == 3){
                        ans += n - j + 1;
                        m[s[i]]--;
                        if(m[s[i]] == 0) m.erase(s[i]);
                        i++;
                    }
    
                }
            }
            
            return ans;
        }
    };