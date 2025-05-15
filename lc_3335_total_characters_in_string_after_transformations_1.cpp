#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // instead of genrating whole string we are just calculating total frequencies
        // z is replaced with ab
        // a with b, b with c and so on till y
        int n = s.size();
        int M = 1000000007;

        vector<int> v1(26, 0);
        for(auto &c : s) {
            v1[c - 'a']++;
        }

        for(int i = 1; i <= t; i++){
            vector<int> v2(26, 0);
            for(int i = 0; i < 26; i++){
                if(i == 25){ // if char is 'z' then add frequencies of 'a' and 'b' by frequencies of 'z'
                    v2[0] = (v2[0] + v1[i]) % M;
                    v2[1] = (v2[1] + v1[i]) % M;
                } // else add frequency of i + 1 by frquency of v1[i]
                else v2[i + 1] = (v2[i + 1] + v1[i]) % M;
            }

            v1 = move(v2);
        }

        int ans  = 0;
        for(int i = 0; i < 26; i++) ans = (ans + v1[i]) % M;
        
        return ans;
    }
};

class Solution { // this solution was not accepted 
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();

        unordered_map<char, int> m;
        for(int i = 0; i < n; i++){ // O(n)
            m[s[i]]++;
        }

        for(int i = 1; i <= t; i++){ // O(t)
            unordered_map<char, int> m1;
            for(auto &p : m){ // O(n) (t.c. is not 26 beacuse map is taking O(n) due to hashing colloisions)
                if(p.first == 'z'){
                    m1['a'] = (m1['a'] + p.second) % 1000000007;
                    m1['b'] = (m1['b'] + p.second) % 1000000007;
                }
                else {
                    m1[(char)(p.first + 1)]  = (m1[(char)(p.first + 1)] + p.second) % 1000000007;
                }
            }
            m = move(m1);
        }

        int ans = 0;
        for(auto p : m){
            ans += p.second;
            ans %= (1000000007);
        }

        // cout << ans;

        return ans;
    }
};