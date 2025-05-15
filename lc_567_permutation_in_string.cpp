#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutation-in-string/?envType=daily-question&envId=2024-10-05

class Solution { // approach 1
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n ==  1 && m == 1) return s1 == s2;

        unordered_map<char, int> mp;

        for(auto c : s1) mp[c]++;

        string temp = s1;
        sort(temp.begin(), temp.end());

        for(int i = 0; i < m; i++){

            if(mp.find(s2[i]) != mp.end()){
                
                string temp2 = "";
                for(int j = i; j < i+n && j < m; j++){
                    temp2 += s2[j];
                }
                sort(temp2.begin(), temp2.end());
                if(temp == temp2) return true;
            }

        }

        return false;

    }
};

class Solution { // approach 2
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n == m){
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s1 == s2;
        }

        unordered_map<char, int> mp;

        for(auto c : s1) mp[c]++;

        int i = 0, j = 0;

        while(j < m){
            if(mp.find(s2[j]) != mp.end()){
                unordered_map<char, int> mp2;
                int x = 0;
                if(n == 1) return true;
                int y = j;
                j++;
                while(y < m){
                    if(mp.find(s2[y]) != mp.end()){
                        mp2[s2[y]]++;
                        if(mp2[s2[y]] > mp[s2[y]]) break;
                        y++;
                        x++;
                    }
                    else break;
                }
                // if(x > n) return false;
                if(n == x) return true;
            }
            else{
                j++;
                i = j;
            }
        }

        return false;

    }
};