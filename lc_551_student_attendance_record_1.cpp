#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/student-attendance-record-i/description/

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int a = 0, l = 0; 

        if(n == 1) return true;

        for(int i = 0; i < n ; i++){
            if(s[i] == 'A'){
                a++;
                if(a == 2) return false;
            }
            if(i > 1 && (s[i] == s[i - 1] && s[i - 1] == s[i - 2] && s[i - 2] == 'L')) return false;
        }

        return true;

    }
};