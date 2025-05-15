#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        for(auto s : words) m[s]++;
        
        int ans = 0;
        int n2 = s.size();
        for(auto p : m){
            string x = p.first;
            int j = 0;
            for(int i = 0; i < n2; i++){
                if(s[i] == x[j]) j++;
                if(j == x.size()) break;
            }
            if(j == x.size()) ans += p.second;
        }

        return ans;

    }
};

// optimized with binary search

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size(), m = s.size();
        map<char, vector<int> >mp;
        unordered_map<string, int> mp2;

        for(int i = 0; i < m; i++) mp[s[i]].push_back(i);

        // to understand this first see leetcode 392
        int ans = 0;
        for(auto s : words) mp2[s]++;

        for(auto p : mp2){
            string x = p.first;
            int freq = p.second;

            // first check if jth element of x is present in map or not
            // if yes then check if it has occured at idx just greater than prev (upper bound)
            // if yes than update prev bcs now this idx have become previous checked idx and nxt time we want that if a char occurs than it should come after this idx only for this x to be a subsequence
            // check above for all chars of x
            // if all have passed then add this x to ans
            int prev = -1, j = 0;
            while(j < x.size()) {

                if(mp.find(x[j]) != mp.end()){ 

                    vector<int> v = mp[x[j]];
                    int idx = -1, lo = 0, hi = v.size() - 1;

                    while(lo <= hi){
                        int mid = lo + (hi - lo)/2;

                        if(v[mid] > prev) {
                            idx = v[mid];
                            hi = mid - 1;
                        }
                        else lo = mid + 1;
                    }

                    if(idx == -1) break;
                    else prev = idx;

                    j++;
                }
                else break;
            }

            if(j == x.size()) ans += freq;

        }

        return ans;

    }
};