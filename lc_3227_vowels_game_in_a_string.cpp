#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();

        /*  
            1. if there is odd number of vowels then alice will remove whole string
            2. if there is even number of vowels then alice will remove (total-vowls - 1) number of vowels so that bob can never win
            3. Hence bob can only win if there is no vowel
        */

        for(int j = 0; j < n; j++) {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') return true;
        }

        return false;
    }
};