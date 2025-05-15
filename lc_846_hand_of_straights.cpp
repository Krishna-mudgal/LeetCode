#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/hand-of-straights/description/

// T.c. = O(N*logN)

class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int k) {
            int n = hand.size();
            sort(hand.begin(), hand.end());
    
            if(n % k != 0) return false;
    
            unordered_map<int, int> m;
            for(auto i : hand) m[i]++;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;
            for(auto p : m) pq1.push({p.first, p.second});
    
            vector<int> v;
            while(!pq1.empty()){
                v.clear();
                for(int i = 0; i < k; i++){
                    v.push_back(pq1.top().first);
                    pq2.push({pq1.top().first, pq1.top().second});
                    pq1.pop();
                }
                int x = v[0];
                for(int i = 0; i < v.size(); i++){
                    if(v[i] != x) return false;
                    x++;
                }
                while(!pq2.empty()){
                    if(pq2.top().second > 1){
                        pq1.push({pq2.top().first, pq2.top().second - 1});
                    }
                    pq2.pop();
                }
            }
    
            return true;
        }
    };