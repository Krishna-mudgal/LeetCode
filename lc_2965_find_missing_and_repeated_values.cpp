#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

class Solution { // better solution then previous one
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int repeated_ele = -1, missing_ele = -1;
            vector<int> v(n*n + 1, 0);
    
            for(auto v2 : grid){
                for(int i : v2){
                    v[i]++;
                }
            }
    
            for(int i = 1; i < v.size(); i++){
                if(v[i] == 2) repeated_ele = i;
                else if(v[i] == 0) missing_ele = i;
            }
    
            return {repeated_ele, missing_ele};
        }
    };

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> v;
    
            for(auto v2 : grid){
                for(auto i : v2){
                    v.push_back(i);
                }
            }
    
            sort(v.begin(), v.end());
    
            set<int> s;
            int missing = 1;
            int repeated_ele = -1;
            int a = -1;
            for(int i : v){
                if(a == i) repeated_ele = i;
                s.insert(i);
                a = i;
            }
    
            for(auto i : s){
                if(i != missing) return {repeated_ele, missing};
                missing++;
            }
    
            if(missing != s.size()) return {repeated_ele, missing};
    
            return {-1, -1};
        }
    };