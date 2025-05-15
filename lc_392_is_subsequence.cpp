#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/is-subsequence/description/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int j = 0;
        for(int i = 0; i < m; i++){
            if(s[j] == t[i]) j++;
            if(j == n) return j == n;
        }

        return j == n;
    }
};  

class Solution {
public:
    bool isSubsequence(string s, string t) { // follow up -> with binary search
    // sbse phle t ki sare element ke index map m store krlo 
    // phir for each element of s check if it's present in map or not
    // if yes then check if it's present at idx just greater than prev
    // if yes then mark prev as this idx bcs we have check at this idx last time
        int n = s.size(), m2 = t.size();

        map<char, vector<int>> m;

        for(int i = 0; i < m2; i++){
            m[t[i]].push_back(i);
        }

        int prev = -1;
        for(int i = 0; i < n; i++){
            if(m.find(s[i]) != m.end()){
                vector<int> v = m[s[i]];
                int idx = -1;
                int lo = 0, hi = v.size() - 1;
                while(lo <= hi){
                    int mid = lo + (hi - lo)/2;

                    if(v[mid] > prev) {
                        idx = v[mid];
                        hi = mid - 1;
                    }
                    else lo = mid + 1;
                }
                // cout << idx << " " << prev << endl;
                if(idx == -1) return false;
                else prev = idx;
            }   
            else return false;
        }
        
        return true;
    }
}; 