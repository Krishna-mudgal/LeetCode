#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/detect-capital/description/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        bool flag = true;

        for(int i = 0; i < n; i++){
            int x = (int)word[i];

            if(x >= 65 && x <= 90){
                continue;
            }
            else {
                flag = false;
                break;
            }
        }

        if(flag == true) return true;

        flag = true;

        for(int i = 1; i < n; i++){
            int x = (int)word[i];

            if(x >= 97 && x <= 122) continue;
            else return false;
        }

        int x = (int)word[0];

        if((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) return true;
        else return false;

    }
};