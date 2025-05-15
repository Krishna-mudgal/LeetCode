#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02

class Solution { // approach - 1
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;

        for(int i = 0; i < n; i++) pq.push({arr[i], i});

        int x = 1;
        while(pq.size() > 0){
            auto p = pq.top();
            pq.pop();

            arr[p.second] = x;

            if(!pq.empty()){
                auto p2 = pq.top();
                if(p.first != p2.first) x++;
            }
        }

        return arr;
    }
};

class Solution { // approach - 2
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int> > v;

        for(int i = 0; i < n; i++) v.push_back({arr[i], i});

        sort(v.begin(), v.end());

        int x = 1;
        for(int i = 0; i < n; i++){
            auto p = v[i];
            arr[p.second] = x;
            if(i < n - 1 && p.first != v[i + 1].first) x++;
        }

        return arr;
    }
}; 