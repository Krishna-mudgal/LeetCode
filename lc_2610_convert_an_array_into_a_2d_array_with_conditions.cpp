#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int> >ans;
        unordered_map<int, int> m;
        for(int i : nums) m[i]++;

        vector<int> v;
        vector<pair<int, int> >v1;
        while(!m.empty()){
            v.resize(0);
            v1.resize(0);
            for(auto p : m){
                int key = p.first;
                int freq = p.second;
                v.push_back(key);
                freq--;

                v1.push_back({key, freq});
            }
            for(auto p : v1){
                if(p.second == 0) m.erase(p.first);
                else m[p.first]--;
            }
            ans.push_back(v);
        }

        return ans;
    }
};