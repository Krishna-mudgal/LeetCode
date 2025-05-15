#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-06

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> m;
        for(int i : banned) m[i]++;

        int ans = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(m.find(i) == m.end()) {
                if(sum + i <= maxSum) {
                    sum += i;
                    ans++;
                }
                else return ans;
            }
        }

        return ans;
    }
};