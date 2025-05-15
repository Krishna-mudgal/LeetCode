#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/car-fleet/

class com {
    public :
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first) return a.second > b.second;
    
            return a.first > b.first;
        }
    };
    class Solution { // T.C. = O(n*log(n))
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            int n = position.size();
            vector<pair<int, int>> v;
            for(int i = 0; i < n; i++){
                v.push_back({position[i], speed[i]});
            }
            sort(v.begin(), v.end(), com());
    
            stack<double> s;
    
            for(int i = 0; i < v.size(); i++){
                double x = ((target - v[i].first)/(double)v[i].second);
                if(s.size() == 0 || x > s.top()) s.push(x);
            }
            
            return s.size();
        }
    };