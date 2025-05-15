#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int ans = 0;

        priority_queue<int> pq;

        for(int i : piles) pq.push(i);

        while(k > 0){
            int x = pq.top();
            pq.pop();

            pq.push(x - floor(x/2));
            k--;
        }

        while(pq.size() > 0){
            ans += pq.top();
            pq.pop();
        }

        return ans;

    }
};