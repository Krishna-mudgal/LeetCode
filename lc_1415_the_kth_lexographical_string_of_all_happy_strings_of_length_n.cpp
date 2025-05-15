#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19

class Solution {
    public:
    
        void helper(vector<string> &v, int &n, string s){
            if(s.size() == n) {
                v.push_back(s);
                return;
            }
    
            if(s.size() == 0 || s[s.size() - 1] != 'a') {
                s += 'a';
                helper(v, n, s);
                s.pop_back();
            }
            if(s.size() == 0 || s[s.size() - 1] != 'b') {
                s += 'b';
                helper(v, n, s);
                s.pop_back();
            }
            if(s.size() == 0 || s[s.size() - 1] != 'c') {
                s += 'c';
                helper(v, n, s);
                s.pop_back();
            }
        }
    
        string getHappyString(int n, int k) {
            vector<string> v;
            helper(v, n, "");
            if(k - 1 >= v.size()) return "";
            else return v[k - 1];
        }
    };