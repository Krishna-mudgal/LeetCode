#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

class Solution { // T.C. = O(n*log(n))
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) { 
        int n = groupSizes.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({groupSizes[i], i});
        }

        sort(v.begin(), v.end());
        
        vector<vector<int>> ans;
        int i = 0;
        while(i < n){
            int grp = v[i].first;
            int x = i;
            vector<int> v2;
            while(i < x + grp){
                v2.push_back(v[i].second);
                i++;
            }

            ans.push_back(v2);
        }

        return ans;
    }
};