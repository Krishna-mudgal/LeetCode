#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04

class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        
        string ans = "";

        int i = 0, j = 0;
        int cnt = 0;
        while(j < n){
            if(cnt == 9){
                ans += '9';
                ans += word[i];
                cnt = 0;
            }
            else if(word[j] == word[i]){
                cnt++;
                j++;
            }
            else {
                if(cnt > 0){
                    ans += (char)(cnt + '0');
                    ans += word[i];
                }
                cnt = 0;
                i = j;
            }
        }

        if(cnt > 0){
            ans += (char)(cnt + '0');
            ans += word[i];
        }

        return ans;

    }
};