#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-distance-in-arrays/description/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        sort(arrays.begin(), arrays.end());

        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq2;

        for(int i = 0; i < n; i++){
            int n = arrays[i].size();
            pq1.push({arrays[i][0], i});
            pq1.push({arrays[i][n - 1], i});
            pq2.push({arrays[i][0], i});
            pq2.push({arrays[i][n - 1], i});
        }

        int ans = INT_MIN;
        while(!pq1.empty()){
            pair<int, int> a = pq1.top();
            pq1.pop();
            
            pair<int, int> b = {INT_MAX, -1};

            stack<pair<int, int>> st;
            while(!pq2.empty()){
                auto p = pq2.top();
                pq2.pop();

                st.push(p);

                if(a.second != p.second) b = p;

                if(b.second != -1) break;

            }
            ans = max(ans, abs(a.first - b.first));

            while(!st.empty()){
                pq2.push(st.top());
                st.pop();
            }
        }

        return ans;

    }
};