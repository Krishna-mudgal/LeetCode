#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04

class Solution { // T.C. = O(26*n) == O(n), S.C = O(n)
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        
        // hr ek char ki left most and right most position nikalo i.e. 26 chars
        // then unke bich m jitne unique element hai unko ans m add krdo

        unordered_set<char> st;
        int ans = 0;
        for(int i = 0; i <= 26; i++){
            char c = i + 97;
            int lo = -1, hi = -1;

            st.clear();
            int j = 0;
            while(j < n){ // marking left most occurence
                if(s[j] == c) {
                    lo = j;
                    break;
                }
                else j++;
            }
            if(lo == -1) continue;

            j = n - 1;
            while(j >= 0){ // marking right most occurence 
                if(s[j] == c) {
                    hi = j;
                    break;
                }
                else j--;
            }
            if(hi == -1) continue;

            j = lo + 1;
            while(j < hi) {
                st.insert(s[j]);
                j++;
            }

            ans += st.size();
        }

        return ans;
    }
};

// one more approach

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        
        // hr ek char ki left most and right most position nikalo
        // then unke bich m jitne unique element hai unko ans m add krdo

        unordered_set<char> st;
        int ans = 0;
        unordered_map<char, vector<int>> m;
        for(int i = 0; i < n; i++){
            if(m.find(s[i]) != m.end()){
                if(m[s[i]].size() == 1) m[s[i]].push_back(i);
                else {
                    m[s[i]].pop_back();
                    m[s[i]].push_back(i);
                }
            }
            else m[s[i]].push_back(i);
        } 

        for(auto p : m){
            if(p.second.size() == 1) continue;
            st.clear();
            for(int i = p.second[0] + 1; i < p.second[1]; i++) st.insert(s[i]);

            ans += st.size();
        }

        return ans;
    }
};