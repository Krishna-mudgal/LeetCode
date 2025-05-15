#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-morse-code-words/description/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<char, string> m;
        char c = 'a';
        for(auto s : v) {
            m[c] = s;
            c++;
        }   

        unordered_set<string> st;
        for(auto w : words){
            string s = "";
            for(auto c : w){
                s += m[c];
            }
            st.insert(s);
        }

        return st.size();
    }
};