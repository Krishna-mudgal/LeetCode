#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25

class Solution {
    public:
    
        bool check(vector<pair<int, int>> &x){
            vector<pair<int, int>> v;
            
            v.push_back(x[0]);
            for(int i = 1; i < x.size(); i++){
                auto p1 = v[v.size() - 1];
                auto p2 = x[i];
    
                // cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
    
                if(p1.second > p2.first){
                    v.pop_back();
                    v.push_back({min(p1.first, p2.first), max(p1.second, p2.second)});
                }
                else v.push_back(p2);
            }
    
            return v.size() >= 3;
        }
    
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            // jitne bhi interval common hai unko merge krdo x coordinates m aur y coordinates m (dono ko alg process krna hai), agr equal hai to merge ni hoge
            // phir dekhlo merge krne ke baad agr total coordinates >= 3 to true return krdo
    
            vector<pair<int, int>> x, y;
    
            for(auto v : rectangles){
                x.push_back({v[0], v[2]});
                y.push_back({v[1], v[3]});
            }
    
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
    
            return (check(x) || check(y));
        }
    };