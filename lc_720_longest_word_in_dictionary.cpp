#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-word-in-dictionary/description/

class Solution {
    public:
        string longestWord(vector<string>& words) {
            int n = words.size();
    
            string ans = "";
            unordered_map<string, int> m;
    
            for(auto s : words) m[s]++;
    
            for(int i = 0; i < n; i++){
                string x = words[i];
                string y = "";
                bool flag = true;
    
                for(int i = 0; i < x.size(); i++){
                    y += x[i];
                    if(m.find(y) == m.end()) {
                        flag = false;
                        break;
                    }
                }
    
                if(flag){
                    if(ans == "") ans = x;
                    else if(ans.size() < x.size()) ans = x;
                    else if(ans.size() == x.size()) ans = min(ans, x);
                }
            }
    
            return ans;
        }
    };