#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i : gifts) pq.push(i);

        while(k > 0){
            auto x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
            k--;
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};