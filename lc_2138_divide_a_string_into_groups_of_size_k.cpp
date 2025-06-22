#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22

class Solution { // T.C. = O(n)
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        int i = 0;
        vector<string> ans;
        string x = "";
        while(i < n){
            int j = i;
            x = "";
            if(j + k >= n){
                while(j < n) {
                    x += s[j];
                    j++;
                }
                while(x.size() < k) x += fill;
            }
            else {
                while(j < n && j < i + k) {
                    x += s[j];
                    j++;
                }
            }

            ans.push_back(x);
            i = j;
        }

        return ans;
    }
};