#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> m;

        int i = 0, j = 9;

        unordered_set<string> st;
        while(j < n){
            string x = "";
            for(int k = i; k <= j; k++){
                x += s[k];
            }

            if(m.find(x) != m.end()){
                st.insert(x);
            }
            else m[x]++;

            i++;
            j++;
        }

        vector<string> ans(st.begin(), st.end());

        return ans;

    }
};