#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        string ans = "";

        for(int i = 0; i < n; i++){
            string c = dictionary[i];
            int a = 0, b = 0;

            while(a < s.size()){
                if(b == c.size()){
                    if(ans.size() <= c.size()){
                        if(ans.size() < c.size() || ans > c) ans = c;
                    }
                    break;
                }
                else if(s[a] == c[b]) {
                    a++;
                    b++;
                }
                else a++;
            }
            if(b == c.size()){
                if(ans.size() <= c.size()){
                    if(ans.size() < c.size() || ans > c) ans = c;
                }
            }
        }

        return ans;

    }
};