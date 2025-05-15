#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/

class Solution {
public:

    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int size = n/k;
        // n/k size ki string nikalo s aut t se aur dekho unki freq same h ya ni if yes to hm s ko rearrange krke t bna skte h
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        int i = 0;
        string x = "";
        while(i < n){
            if(x.size() < size){
                x += s[i];
                i++;
            }
            else {
                m1[x]++;
                x = "";
            }
        }
        m1[x]++;

        i = 0;
        x = "";
        while(i < n){
            if(x.size() < size){
                x += t[i];
                i++;
            }
            else {
                m2[x]++;
                x = "";
            }
        }
        m2[x]++;

        for(auto p : m1){
            if(m2[p.first] != p.second) return false;
        }

        return true;
    }
};