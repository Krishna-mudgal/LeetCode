#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    string getString(queue<char> &q){
        string s2;
        int n = q.size();

        for(int i = 0; i < n; i++){
            s2 += q.front();
            q.push(q.front());
            q.pop();
        }

        return s2;
    }
    bool rotateString(string s, string goal) {
        int n = s.size();
        queue<char> q;
        string s2 = "";

        for(char c : s) q.push(c);

        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();

            string s2 = getString(q);

            if(s2 == goal) return true;
        }

        return false;

    }
};