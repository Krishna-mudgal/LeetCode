#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11

class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();

        string t = "";
        unordered_map<char, int> mp;
        for(char i : s) if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') mp[i]++;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                if(mp.find('A') != mp.end())  {
                    t += 'A';
                    mp['A']--;
                    if(mp['A'] == 0) mp.erase('A');
                } else if(mp.find('E') != mp.end()) {
                    t += 'E';
                    mp['E']--;
                    if(mp['E'] == 0) mp.erase('E');
                } else if(mp.find('I') != mp.end()) {
                    t += 'I';
                    mp['I']--;
                    if(mp['I'] == 0) mp.erase('I');
                } else if(mp.find('O') != mp.end()) {
                    t += 'O';
                    mp['O']--;
                    if(mp['O'] == 0) mp.erase('O');
                } else if (mp.find('U') != mp.end()) {
                    t += 'U';
                    mp['U']--;
                    if(mp['U'] == 0) mp.erase('U');
                }
                else if(mp.find('a') != mp.end())  {
                    t += 'a';
                    mp['a']--;
                    if(mp['a'] == 0) mp.erase('a');
                } else if(mp.find('e') != mp.end()) {
                    t += 'e';
                    mp['e']--;
                    if(mp['e'] == 0) mp.erase('e');
                } else if(mp.find('i') != mp.end()) {
                    t += 'i';
                    mp['i']--;
                    if(mp['i'] == 0) mp.erase('i');
                } else if(mp.find('o') != mp.end()) {
                    t += 'o';
                    mp['o']--;
                    if(mp['o'] == 0) mp.erase('o');
                } else if (mp.find('u') != mp.end()) {
                    t += 'u';
                    mp['u']--;
                    if(mp['u'] == 0) mp.erase('u');
                }
            } else t += s[i];
        }

        return t;
    }
};