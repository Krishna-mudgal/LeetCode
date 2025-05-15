#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/ransom-note/description/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1;
        int n = ransomNote.size(), m = magazine.size();

        for(int i = 0; i < m; i++) m1[magazine[i]]++;

        for(int i = 0; i < n; i++){
            if(m1.find(ransomNote[i]) != m1.end()){
                m1[ransomNote[i]]--;
                if(m1[ransomNote[i]] == 0) m1.erase(ransomNote[i]);
            }
            else return false;
        }

        return true;

    }
};