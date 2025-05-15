#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-genetic-mutation/description/

class Solution {
public:
    int helper(string s1, string &s2, unordered_set<string> &st, unordered_set<string> visited){

        // visited string wala ek set bnana pdega kyu ki ho skta h hmne kch change kiye aur string ki state x pr phuche aur phir isme kiye to state y m phoche aur phir isme kch kiye to phir se x pr phuch gye to infinite loop le jyga to yh maintain krna pdega
        
        if(s1 == s2) return 0;
        
        int ans = INT_MAX;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != 'A'){
                char c = s1[i];
                s1[i] = 'A';

                if(st.find(s1) != st.end() && visited.find(s1) == visited.end()) {
                    visited.insert(s1);
                    int x = helper(s1, s2, st, visited);
                    if(x != -1) ans = min(ans, 1 + x);
                    visited.erase(s1);
                }

                s1[i] = c;
            }
            if(s1[i] != 'C'){
                char c = s1[i];
                s1[i] = 'C';

                if(st.find(s1) != st.end() && visited.find(s1) == visited.end()) {
                    visited.insert(s1);
                    int x = helper(s1, s2, st, visited);
                    if(x != -1) ans = min(ans, 1 + x);
                    visited.erase(s1);
                }

                s1[i] = c;
            }
            if(s1[i] != 'G'){
                char c = s1[i];
                s1[i] = 'G';

                if(st.find(s1) != st.end() && visited.find(s1) == visited.end()) {
                    visited.insert(s1);
                    int x = helper(s1, s2, st, visited);
                    if(x != -1) ans = min(ans, 1 + x);
                    visited.erase(s1);
                }

                s1[i] = c;
            }
            if(s1[i] != 'T'){
                char c = s1[i];
                s1[i] = 'T';

                if(st.find(s1) != st.end() && visited.find(s1) == visited.end()) {
                    visited.insert(s1);
                    int x = helper(s1, s2, st, visited);
                    if(x != -1) ans = min(ans, 1 + x);
                    visited.erase(s1);
                }

                s1[i] = c;
            }
        }

        return ((ans == INT_MAX) ? -1 : ans);
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {       
        if(bank.size() == 0) return -1;

        unordered_set<string> st, visited;
        for(auto s : bank) st.insert(s);

        return helper(startGene, endGene, st, visited);
    }
};