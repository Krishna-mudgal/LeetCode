#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<long long, vector<long long> , greater<long long>> pq;
        int ans = 0;

        for(int i : nums) pq.push(i);

        while(pq.size() > 1){
            long long x = pq.top();
            pq.pop();
            if(x >= k) return ans;
            long long y = pq.top();
            pq.pop();
            long long z = x * 2 + y;
            pq.push(z);
            ans++;
        }

        return ans;

    }
};