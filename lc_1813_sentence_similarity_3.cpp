#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sentence-similarity-iii/

class Solution {
public:

    bool check(vector<string> &v1, vector<string> &v2){
        int i = 0, j = v1.size() - 1;
        int a = 0, b = v2.size() - 1;

        while(a < v2.size() && a <= b){
            if(v2[a] == v1[i]){
                i++;
                a++;
            }
            else if(v2[b] == v1[j]){
                j--;
                b--;
            }
            else return false;
        }

        return true;
    }

    bool areSentencesSimilar(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(s1 == s2) return true;

        vector<string> v1, v2;
        string x = "";

        for(int i = 0; i < n; i++){
            if(s1[i] == ' '){
                v1.push_back(x);
                x = "";
            }
            else x += s1[i];
        }
        v1.push_back(x); // to push last word

        x = "";
        for(int i = 0; i < m; i++){
            if(s2[i] == ' ') {
                v2.push_back(x);
                x = "";
            }
            else x += s2[i];
        }
        v2.push_back(x); // to push last word

        // for(auto s : v1) cout << s << endl;
        // for(auto s : v2) cout << s << endl;

        return (v1.size() > v2.size()) ? check(v1, v2) : check(v2, v1);
    }
};