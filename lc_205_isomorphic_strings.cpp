#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/isomorphic-strings/

class Solution { // T.C. = O(n)
    public:
        bool isIsomorphic(string s, string t) {
            int n = t.size();
            unordered_map<char, char> m1, m2;
            for(int i = 0; i < n; i++){
                if(m2.find(t[i]) == m2.end()){
                    m1[s[i]] = t[i];
                    m2[t[i]] = s[i];
                }
            }
    
            for(int i = 0; i < n; i++){
                if(m1.find(s[i]) == m1.end()) return false;
                else s[i] = m1[s[i]];
            }
    
            return s == t;
        }
    };

    // without map
    class Solution { // T.C. = O(n)
        public:
            bool isIsomorphic(string s, string t) {
                int n = t.size();
                vector<int> v(150,  500);
                for(int i = 0; i < n; i++){
                    if(v[s[i]] == 500 || v[s[i]] == (s[i] - t[i])) v[s[i]] = (s[i] - t[i]);
                    else return false;
                }
        
                v.clear();
                v.resize(150, 500);
                for(int i = 0; i < n; i++){
                    if(v[t[i]] == 500 || v[t[i]] == (s[i] - t[i])) v[t[i]] = (s[i] - t[i]);
                    else return false;
                }
        
        
                return true;
            }
        };