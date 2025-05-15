#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<float, pair<float, float> >, vector<pair<float, pair<float, float> >>, greater<pair<float, pair<float, float> >> > pq;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                pq.push({(arr[i]/(float)(arr[j])), {arr[i], arr[j]}});
            }
        }

        int i = 1;
        while(i < k){
            pq.pop();
            i++;
        }

        auto p = pq.top();
        return {(int)p.second.first, (int)p.second.second};
    }
};