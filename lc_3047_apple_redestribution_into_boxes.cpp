#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=daily-question&envId=2025-12-24

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int cnt = 0;
        for(int &i: apple) cnt += i;
        int ans = 0;
        sort(capacity.begin(), capacity.end(), greater<int>());
        for(int &i: capacity) {
            if(cnt <= 0) return ans;
            cnt -= i;
            ans++;
        }

        return ans;
    }
};