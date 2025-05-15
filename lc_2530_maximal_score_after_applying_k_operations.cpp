#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2024-10-14

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        priority_queue<int> pq;

        for(int i : nums) pq.push(i);

        while(k > 0){
            double x = pq.top();
            pq.pop();
            ans += x;
            int y = ceil(x/3);
            pq.push(y);
            k--;
        }

        return ans;

    }
};