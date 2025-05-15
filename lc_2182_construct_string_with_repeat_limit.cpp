#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-string-with-repeat-limit/description/?envType=daily-question&envId=2024-12-17

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();

        unordered_map<char, int> m;
        priority_queue<pair<char, int>> pq;

        for(auto c : s) m[c]++;
        for(auto p : m) pq.push({p.first, p.second});

        string ans = "";

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            if(p.second <= repeatLimit){
                for(int i = 0; i < p.second; i++) ans += p.first;
            }
            else {
                for(int i = 0; i < repeatLimit; i++) {
                    ans += p.first;
                    p.second--;
                }

                if(pq.empty()) return ans;

                auto p2 = pq.top();
                pq.pop();

                ans += p2.first;
                p2.second--;

                if(p.second > 0) pq.push({p.first, p.second});
                if(p2.second > 0) pq.push({p2.first, p2.second});
            }
        }

        return ans;

    }
};