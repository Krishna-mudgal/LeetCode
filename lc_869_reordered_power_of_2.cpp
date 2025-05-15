#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reordered-power-of-2/description/

class Solution { // T.C. = ((s.size())!)
    public:
    
        bool check(string s){ // checks each premutations
            if(s[0] == '0') return false;
    
            int n = stoi(s);
            while(n > 1){
                if(n % 2 != 0) return false;
    
                n /= 2;
            }
    
            return true;
        }
    
        bool helper(string &s, int idx){ // calculates premutation
            if(idx == s.size()){
                // cout << s << endl;
                if(check(s)) return true;
                else return false;
            }
    
            bool ans = false;
            for(int i = idx; i < s.size(); i++){
                swap(s[i], s[idx]);
                ans = ans | helper(s, idx + 1);
                swap(s[i], s[idx]);
                if(ans == true) return true;
            }
    
            return ans;
        }
    
        bool reorderedPowerOf2(int n) {
            string s = to_string(n);
            return helper(s,  0);
        }
    };