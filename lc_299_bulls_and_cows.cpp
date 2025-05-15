#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/bulls-and-cows/description/

class Solution { // time : O(n), space = O(n)
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        unordered_map<int, int> m;

        for(char c : secret) m[c - '0']++;

        int bulls = 0, cows = 0;

        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]) {
                bulls++;
                m[guess[i] - '0']--;
                if(m[guess[i] - '0'] == 0) m.erase(guess[i] - '0');
            }
        }

        for(int i = 0; i < n; i++){
            if(secret[i] != guess[i]) {
                if(m.find(guess[i] - '0') != m.end()){
                    cows++;
                    m[guess[i] - '0']--;
                    if(m[guess[i] - '0'] == 0) m.erase(guess[i] - '0');
                }
            }
        }

        string ans = "";
        ans += to_string(bulls);
        ans += 'A';
        ans += to_string(cows);
        ans += 'B';

        return ans;
    }
};