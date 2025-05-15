#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        vector<string> v;
        int j = 0;
        string x = "";
        while(j <= n){
            if(j == n){
                if(x != "") v.push_back(x);
                break;
            }
            else if(sentence[j] == ' '){
                if(x != "") v.push_back(x);
                j++;
                x = "";
            }
            else{
                x += sentence[j];
                j++;
            }
        }

        for(int i = 0; i < v.size() - 1; i++){
            auto s1 = v[i];
            auto s2 = v[i + 1];

            if(s1[s1.size() - 1] != s2[0]) return false;
        }
        
        auto s1 = v[0];
        auto s2 = v[v.size() - 1];

        if(s1[0] != s2[s2.size() - 1]) return false;

        return true;
    }
};

class Solution { // more optimized
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        if(sentence[0] != sentence[n - 1]) return false;
        for(int i = 0; i < n - 1; i++){
            if(sentence[i] == ' '){
                if(sentence[i - 1] != sentence[i + 1]) return false;
            }
        }
        
        return true;
    }
};