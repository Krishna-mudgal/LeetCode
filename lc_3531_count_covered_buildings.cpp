#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-covered-buildings/description/?envType=daily-question&envId=2025-12-11

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> mp1, mp2;
        sort(buildings.begin(), buildings.end());

        for(int i = 0; i < buildings.size(); i++) {
            if(mp1.find(buildings[i][0]) != mp1.end()) {
                mp1[buildings[i][0]].second = max(mp1[buildings[i][0]].second, buildings[i][1]);
                mp1[buildings[i][0]].first = min(mp1[buildings[i][0]].first, buildings[i][1]);
            }
            else {
                mp1[buildings[i][0]].first = buildings[i][1];
                mp1[buildings[i][0]].second = buildings[i][1];
            }

            if(mp2.find(buildings[i][1]) != mp2.end()) {
                mp2[buildings[i][1]].second = max(mp2[buildings[i][1]].second, buildings[i][0]);
                mp2[buildings[i][1]].first = min(mp2[buildings[i][1]].first, buildings[i][0]);
            }
            else {
                mp2[buildings[i][1]].second = buildings[i][0];
                mp2[buildings[i][1]].first = buildings[i][0];
            }
        }

        int ans = 0;
        for(auto &p : buildings) {
            int x = p[0], y = p[1];
            if(y < mp1[x].second && y > mp1[x].first && x < mp2[y].second && x > mp2[y].first) ans++;
        }

        return ans;
    }
};

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, vector<int>> mp1, mp2;
        unordered_map<long long, int> flag;

        auto key = [&](int x, int y) {
            return (long long)x << 32 | y;
        };

        sort(buildings.begin(), buildings.end());

        for (auto &b : buildings) {
            mp1[b[0]].push_back(b[1]);
            mp2[b[1]].push_back(b[0]);
        }

        // process rows
        for (auto &p : mp1) {
            auto &v = p.second;
            sort(v.begin(), v.end());
            if (v.size() > 2) {
                for (int i = 1; i < v.size() - 1; i++)
                    flag[key(p.first, v[i])]++;  
            }
        }

        // process columns
        for (auto &p : mp2) {
            auto &v = p.second;
            sort(v.begin(), v.end());
            if (v.size() > 2) {
                for (int i = 1; i < v.size() - 1; i++)
                    flag[key(v[i], p.first)]++;  
            }
        }

        int ans = 0;
        for (auto &kv : flag) {
            if (kv.second == 2) ans++;  // covered from both row + column
        }

        return ans;
    }
};
