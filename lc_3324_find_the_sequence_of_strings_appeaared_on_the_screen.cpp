#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/

class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();

        vector<string> ans;

        string x = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 26; j++){
                x += (char)(97 + j);
                ans.push_back(x);
                if(x.back() == target[i]) break;
                x.pop_back();
            }
        }

        return ans;

    }
};