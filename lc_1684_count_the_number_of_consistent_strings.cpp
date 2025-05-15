#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=daily-question&envId=2024-09-12


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size(), m = allowed.size();
        int ans = 0;
        unordered_map<char, int> m1;

        for(int i = 0; i < m; i++) m1[allowed[i]]++;

        for(int i = 0; i < n; i++){
            bool flag = true;
            for(int j = 0; j < words[i].size(); j++){
                if(m1.find(words[i][j]) == m1.end()){
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }

        return ans;
    }
};