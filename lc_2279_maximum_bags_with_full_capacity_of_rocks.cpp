#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

class cmp{
public : 
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return (p1.first - p1.second) < (p2.first - p2.second);
    }
};

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) { // greedy + sorting

        vector<pair<int, int>> v;
        int ans = 0;

        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] - rocks[i] == 0) ans++;
            else v.push_back({capacity[i], rocks[i]});
        }

        sort(v.begin(), v.end(), cmp());

        int i = 0;
        while(additionalRocks > 0 && i < v.size()){
            auto p = v[i];
            int cap = p.first, rock = p.second;

            if((cap - rock) <= additionalRocks){
                additionalRocks -= (cap - rock);
                ans++;
            }

            i++;

        }

        return ans;
        
    }
};