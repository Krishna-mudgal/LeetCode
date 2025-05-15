#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08

class Solution {
public:
    bool helper(string x, string y){
        if(y.size() < x.size()) return false;
        int n = y.size(), m = x.size();

        for(int i = 0; i < m; i++){
            if(y[i] != x[i] || y[n - x.size() + i] != x[i]) return false;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(helper(words[i], words[j])) ans++;
            }
        }

        return ans;
    }
};