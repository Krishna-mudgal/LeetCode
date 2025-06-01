#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution { // T.C. = O(26*n + m) == O(n + m)
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, int> m1, m2;
        for(auto c : p) m1[c]++;

        int i = 0, j = 0;
        while(j < p.size() - 1){
            m2[s[j]]++;
            j++;
        }


        int x = 0;
        bool flag = true;

        while(j < n){
            m2[s[j]]++;
            flag = true;
            for(auto p : m2){
                if((m1.find(p.first) == m1.end()) || p.second > m1[p.first]){
                    flag = false;
                    break;
                }
            } 

            if(flag) ans.push_back(i);

            m2[s[i]]--;
            if(m2[s[i]] == 0) m2.erase(s[i]);
            i++;
            j++;
        }

        return ans;

    }
};