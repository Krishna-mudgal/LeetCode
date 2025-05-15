#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-completing-word/description/

class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
        int n = l.size();

        unordered_map<char, int> m;
        for(int i = 0; i < n; i++){
            if(!isdigit(l[i]) && l[i] != ' ') {
                if(isupper(l[i])) m[(char)(l[i] + 32)]++;
                else m[l[i]]++;
            }
        }

        string ans = "";
        unordered_map<char, int> m2;
        for(int i = 0; i < words.size(); i++){
            string x = words[i];
            m2 = m;
            for(int j = 0; j < x.size(); j++){
                if(m2.find(x[j]) != m2.end()){
                    m2[x[j]]--;
                    if(m2[x[j]] == 0) m2.erase(x[j]);
                }
            }

            if(m2.size() == 0) {
                if(ans == "") ans = x;
                else if(ans.size() > x.size()) ans = x;
            }
        }

        return ans;

    }
};