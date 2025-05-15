#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/groups-of-special-equivalent-strings/description/

class Solution {
    public:
        int numSpecialEquivGroups(vector<string>& words) {
            int n = words.size();
            unordered_map<string, vector<string>> m;
    
            // har ek string ke odd place walo ko alg add kro phir even ko bhi alg string bna kr add kro
            // inko sort krke add krke map m store krdo
            // ab next string agr es group ko belong krta hoga to upar process krne ke baad us group ke map m store hojyga
            // yh isliye work kr rha h kyu ki sort apn odd places ko hi swap krskte h odd ke sath and even ko even ke sath to isliye dono ko alg alg consider krna pd rha h, to agr koi do string swap krne pr equal hoskte h to sort krne pr same order a jyga (odd ko alg sort and even ko alg sort)
    
            for(auto s : words){
                string x = "", y = "";
                for(int i = 0; i < s.size(); i++){
                    if(i % 2 == 0) x += s[i];
                    else  y += s[i];
                }
                sort(x.begin(), x.end());
                sort(y.begin(), y.end());
                m[(x + y)].push_back(s);
            }
    
            return m.size();
        }
    };