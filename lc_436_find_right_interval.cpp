#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-right-interval/description/

class Solution { // T.C. = O(n*logn)
public:

    int helper(vector<vector<int>> &v, int val) {
        int lo = 0, hi = v.size() - 1; 

        int ans = INT_MAX;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(v[mid][0] >= val) {
                ans = v[mid][2];
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({intervals[i][0], intervals[i][1], i});
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = helper(v, intervals[i][1]);
        }

        return ans;
    }
};