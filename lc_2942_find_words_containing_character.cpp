#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            for(char c : s) {
                if(c == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};