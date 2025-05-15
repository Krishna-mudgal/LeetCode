#include <bits/stdc++.h>
using namespace std;

https://leetcode.com/problems/merge-intervals/description/

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();

        int i = n - 1;

        while(i >= 0){
            auto curr = intervals[i];
            if(ans.size() == 0) ans.push_back({curr[0], curr[1]});
            else {
                auto last = ans[ans.size() - 1];
                if(curr[1] >= last[0]) { // curr(intervals[i]).end >= last.start -> overlapping
                    ans.pop_back();
                    int mx = max(curr[1], last[1]);
                    int mn = min(curr[0], last[0]);
                    ans.push_back({mn, mx});
                }
                else ans.push_back({curr[0], curr[1]});
            }
            
            i--;
        }

        return ans;

    }
};