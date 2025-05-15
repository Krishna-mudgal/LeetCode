#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        unordered_map<string, int> m1;
        vector<string> ans;

        string s = "";
        for(int i = 0; i < n; i++){
            if(s1[i] == ' '){
                m1[s]++;
                s = "";
            }
            else s += s1[i];
        }

        m1[s]++;
        s = "";

        for(int i = 0; i < m; i++){
            if(s2[i] == ' '){
                m1[s]++;
                s = "";
            }
            else s += s2[i];
        }   

        m1[s]++;

        for(auto p : m1){
            if(p.second == 1) ans.push_back(p.first);
        }   

        return ans;

    }
};