#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/keyboard-row/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();

        unordered_map<char, int> m1, m2, m3;

        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
        for(int i = 0; i < s1.size(); i++){
            m1[s1[i]] = 1;
            m1[(char)(s1[i] - 32)] = 1;
            if(i < s2.size()) {
                m2[s2[i]] = 2;
                m2[(char)(s2[i] - 32)] = 2;
            }
            if(i < s3.size()){
                m3[s3[i]] = 3;
                m3[(char)(s3[i] - 32)] = 3;
            }
        }

        vector<string> ans;

        bool flag1 = true, flag2 = true, flag3 = true;
        for(int i = 0; i < n; i++){

            flag1 = true, flag2 = true, flag3 = true;
            for(int j = 0; j < words[i].size(); j++){
                if(flag1 && m1.find(words[i][j]) == m1.end()) flag1= false;
                if(flag2 && m2.find(words[i][j]) == m2.end()) flag2= false;
                if(flag3 && m3.find(words[i][j]) == m3.end()) flag3= false;
            }

            if(flag1 || flag2 || flag3) ans.push_back(words[i]);

        }

        return ans;

    }
};