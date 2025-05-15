#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20

class Solution {
    public:
    
        void helper(vector<string> &v, int &n, string s){
            if(s.size() == n) {
                v.push_back(s);
                return;
            }
    
            s += '0';
            helper(v, n, s);
            s.pop_back();
            
            s += '1';
            helper(v, n, s);
            s.pop_back();
        }
    
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            vector<string> v;
            helper(v, n, "");
    
            unordered_map<string, int> m;
    
            for(auto s : nums) m[s]++;
    
            for(auto s : v){
                if(m.find(s) == m.end()) return s;
            }
    
            return "";
        }
    };