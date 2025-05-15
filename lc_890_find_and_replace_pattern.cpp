#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-and-replace-pattern/description/

class Solution { // T.C. O(n*(maxsize_of_word))
    public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            int n = words.size();
            // sort(pattern.begin(), pattern.end());
            vector<string> ans;
            unordered_map<char, char> m1, m2;
            for(auto s : words){
                if(s.size() == pattern.size()){
                    if(s == pattern) {
                        ans.push_back(s);
                        continue;
                    }
    
                    m1.clear();
                    m2.clear();
                    bool flag = true;
                    for(int i = 0; i < s.size(); i++){
                        if((m2.find(pattern[i]) == m2.end() || m2[pattern[i]] == s[i]) && (m1.find(s[i]) == m1.end() || m1[s[i]] == pattern[i])){
                            m1[s[i]] = pattern[i];
                            m2[pattern[i]] = s[i];
                        }
                        else flag = false; // means ki ya to mene pattern[i] ke liye character already choose krliya h or ab same pattern[i] ke liye dusra character lene ki baat ho rhi h ya s[i] ke liye character already choose krliya hai or ab s[i] ke liye dusra character lene ki baat ho rhi h
                    }
    
                    if(flag == false) continue;
            
                    for(int i = 0; i < s.size(); i++){
                        if(m1.find(s[i]) == m1.end()) {
                            flag = false;
                            break;
                        }
                    }
    
                    if(flag) ans.push_back(s);
                }
            }
    
            return ans;
        }
    };