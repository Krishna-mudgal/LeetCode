#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();

        unordered_set<string> s1;

        for(int i = 0; i < n; i++){

            string a = to_string(arr1[i]);
            string b = "";
            for(int j = 0; j < a.size(); j++){
                b += a[j];
                s1.insert(b);
            }
            
        }

        int ans = 0;

        for(int i = 0; i < m; i++){

            string a = to_string(arr2[i]);
            string b = "";

            for(int j = 0; j < a.size(); j++){
                b += a[j];
                if(s1.find(b) != s1.end() && ans < b.size()) ans = b.size();
            }

        }

        return ans;

    }
};