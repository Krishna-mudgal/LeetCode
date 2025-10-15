#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/?envType=daily-question&envId=2025-10-13

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> ans;
        unordered_map<char, int> mp;
        int i = 1;
        bool flag = true;
        ans.push_back(words[0]);
        while(i < n) {
            string s1 = ans.back();
            mp.clear();
            for(auto c : s1) mp[c]++;
            unordered_map<char, int> mp2 = mp;
            while(i < n) {
                string s2 = words[i];
                if(s2.size() > s1.size() || s2.size() < s1.size()) {
                    ans.push_back(s2);
                    break;
                }
                mp = mp2;
                for(auto c : s2) {
                    if(mp.find(c) == mp.end()) {
                        break;
                    } else {
                        mp[c]--;
                        if(mp[c] == 0) mp.erase(c);
                    }
                }

                if(mp.size() != 0) {
                    ans.push_back(s2);
                    break;
                } else i++;
            }
        }

        return ans;
    }
};