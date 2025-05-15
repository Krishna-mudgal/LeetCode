#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size(), m = order.size();
        unordered_map<char, int> m1;

        for(char c : s) m1[c]++;

        string ans = "";
        for(char c : order) {
            if(m1.find(c) != m1.end()){
                int x = m1[c];
                for(int i = 0; i < x; i++) ans += c;
                m1.erase(c);
            }
        }

        for(auto p : m1){
            for(int i = 0; i < p.second; i++) ans += p.first;
        }

        return ans;
    }
};