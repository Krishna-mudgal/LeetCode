#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-values-from-labels/description/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({values[i], labels[i]});
        sort(v.begin(), v.end());

        int i = n - 1;
        int ans = 0, ele = 0;
        unordered_map<int, int> mp;
        while(i >= 0 && ele < numWanted) {
            if(mp[v[i].second] < useLimit) {
                ans += v[i].first;
                mp[v[i].second]++;
                ele++;
            } 
            i--;
        }   

        return ans;
    }
};