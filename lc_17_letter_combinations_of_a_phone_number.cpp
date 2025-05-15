#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();

        if(n == 0) return {};

        unordered_map<char, string> m;

        for(auto i : digits) {
            string s = "";
            if(i == '2') s = "abc";
            else if (i == '3') s = "def";
            else if(i == '4') s = "ghi";
            else if(i == '5') s = "jkl";
            else if(i == '6') s = "mno";
            else if(i == '7') s = "pqrs";
            else if(i == '8') s = "tuv";
            else if(i == '9') s = "wxyz";

            m[i] = s;
        }
        
        vector<string> v;
        for(auto i : digits) v.push_back(m[i]);

        vector<string> ans;

        if(v.size() == 1) {
            for(int i = 0; i < v[0].size(); i++) {
                string t = "";
                t += v[0][i];
                ans.push_back(t);
            }
        }
        else if(v.size() == 2){
            for(auto a : v[0]) {
                string t = "";
                t += a;
                for(auto b : v[1]){
                    t += b;
                    ans.push_back(t);
                    t.pop_back(); // backtracking
                }
            }
        }
        else if(v.size() == 3){
            for(auto a : v[0]){
                string t = "";
                t += a;
                for(auto b : v[1]){
                    t += b;
                    for(auto c : v[2]){
                        t += c;
                        ans.push_back(t);
                        t.pop_back(); // backtracking
                    }
                    t.pop_back(); // backtracking
                }
            }
        }
        else {
            for(auto a : v[0]){
                string t = "";
                t += a;
                for(auto b : v[1]){
                    t += b;
                    for(auto c : v[2]){
                        t += c;
                        for(auto d : v[3]){
                            t += d;
                            ans.push_back(t);
                            t.pop_back(); // backtracking
                        }
                        t.pop_back(); // backtracking
                    }
                    t.pop_back(); // backtracking
                }
            }
        }

        return ans;

    }
};