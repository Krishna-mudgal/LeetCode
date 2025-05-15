#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int, char> >pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        while(pq.size() > 0){
            auto p1 = pq.top();
            pq.pop();

            if(ans.size() > 1 && ans[ans.size() - 1] == p1.second && ans[ans.size() - 2] == p1.second){
                if(pq.empty()) break;
                
                auto p2 = pq.top();
                pq.pop();

                ans += p2.second;
                p2.first--;

                if(p2.first > 0) pq.push(p2);
            }
            else {
                ans += p1.second;
                p1.first--;
            }

            if(p1.first > 0) pq.push(p1);
        }

        return ans;
    }
};