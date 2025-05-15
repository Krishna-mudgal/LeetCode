#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int n = meetings.size();
    
            sort(meetings.begin(), meetings.end());
            vector<pair<int, int>> v;
    
            v.push_back({meetings[0][0], meetings[0][1]});
            for(int i = 1; i < n; i++){
                auto p1 = v[v.size() - 1];
                pair<int, int> p2 = {meetings[i][0], meetings[i][1]};
    
                if(p1.second >= p2.first){
                    v.pop_back();
                    v.push_back({min(p1.first, p2.first), max(p1.second, p2.second)});
                }
                else v.push_back(p2);
            }
    
            int ans = 0;
    
            if(v[0].first - 1 > 0) ans += v[0].first - 1;
                
            for(int i = 0; i < v.size() - 1; i++){
                // cout << v[i].first << " " << v[i].second << endl;
                int gap = v[i + 1].first - v[i].second - 1;
                if(gap > 0) ans += gap;
            }
    
            if(days - v[v.size() - 1].second > 0) ans += days - v[v.size() - 1].second;
    
            return ans;
        }
    };