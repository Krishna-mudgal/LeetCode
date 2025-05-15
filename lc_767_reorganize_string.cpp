#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char, int> m;
        priority_queue<pair<int, char> >pq;

        for(auto e : s) m[e]++;

        for(auto p : m) pq.push({p.second, p.first});

        string ans = "";

        while(pq.size() > 0){
            auto p = pq.top();
            pq.pop();

            if((ans.size() == 0) || (ans[ans.size() - 1] != p.second)){
                ans += p.second;
                p.first--;
                if(p.first > 0) pq.push({p.first, p.second});
            }
            else {
                if(pq.empty()) return "";
                auto p2 = pq.top();
                pq.pop();

                ans += p2.second;
                p2.first--;

                if(p.first > 0) pq.push({p.first, p.second});
                if(p2.first > 0) pq.push({p2.first, p2.second});
            }

        }

        return ans;

    }
};