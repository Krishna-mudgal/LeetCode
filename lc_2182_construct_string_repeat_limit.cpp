#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-string-with-repeat-limit/description/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        priority_queue<pair<char, int> > pq; // to apply greedy logic
        unordered_map<char, int> m; // to store frequency
        int n = s.size();

        for(int i = 0; i < n; i++){
            m[s[i]]++;
        }

        for(auto p : m){
            pq.push(p);
        }

        string ans = "";
        while(pq.size() > 0){
            pair<char, int> p1 = pq.top();
            pq.pop();

            char mx = p1.first;
            int mx_frq = p1.second;

            if(mx_frq <= repeatLimit){ // agr repeat limit se kam h to mx char poora hi daal do phir nxt iteration m sec mx ajyga
                int x = mx_frq;
                for(int i = 0; i < x; i++){
                    ans += mx;
                    mx_frq--;
                }
            }
            else{ // repeat limit tk daal do then ek bar sec_mx daal do phir if their freq is > 0 then push them again in pq

                for(int i = 0; i < repeatLimit; i++){
                    ans += mx;
                    mx_frq--;
                }

                if(pq.size() == 0) return ans;

                auto p2 = pq.top();
                pq.pop();

                char sec_mx = p2.first;
                int sec_mx_frq = p2.second;

                ans += sec_mx;
                sec_mx_frq--;

                if(mx_frq > 0) pq.push({mx, mx_frq});
                if(sec_mx_frq > 0) pq.push({sec_mx, sec_mx_frq});
            }

        }

        return ans;

    }
};