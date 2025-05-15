#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0, j = 0;
        string s = "";
        while(i < n){
            if(j == n){
                s += chars[i];
                if(j - i != 1) s += to_string(j - i);
                i = j;
            }
            else if(chars[j] == chars[i]) j++;
            else{
                s += chars[i];
                if(j - i != 1) s += to_string(j - i);
                i = j;
            }
        }
        
        chars.clear();
        chars.resize(0);
        
        i = 0;
        while(i < s.size()){
            if(isdigit(s[i])){
                string x = "";
                while(i < s.size() && isdigit(s[i])){
                    x += s[i];
                    i++;
                }
                for(auto c : x){
                    chars.push_back(c);
                }
            }
            else {
                chars.push_back(s[i]);
                i++;
            }
        }

        return chars.size();
    }
};