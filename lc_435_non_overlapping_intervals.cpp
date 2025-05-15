#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/description/

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) { 

        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int n = intervals.size();

        stack<vector<int> >s;
        
        for(int i = n - 1; i >= 0; i--) s.push(intervals[i]);

        while(s.size() > 1){
            auto a = s.top();
            s.pop();

            auto b = s.top();
            s.pop();

            if(a[1] > b[0]){ // if overlapping then remove that one whose end time is maximum bcs if we retain that one then chances of overlapping future increases 
                ans++;
                if(a[1] > b[1]) s.push(b);
                else s.push(a);
            }
            else s.push(b); // if not then next time we have to compare with second one so remove first
        }

        return ans;
    }
};

//more optimised -> approach 2

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {// more optimized

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);
        int lastEndTime = intervals[0][1];
        int ans = 0;

        for(int i = 1; i < n; i++){
            // cout << lastEndTime << " " << intervals[i][0] << " " << intervals[i][1] << endl ;
            if(lastEndTime > intervals[i][0]) ans++; // if overlapping then remove current one by not considering it's end time
            else lastEndTime = intervals[i][1];
        }

        return ans;
        
    }
};

// approach 2 variation - 2

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {// more optimized

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);

        for(auto v : intervals) cout << v[0] << " " << v[1] << endl;
        int lastFirstTime = intervals[n - 1][0];
        int ans = 0;

        for(int i = n-2; i >= 0; i--){
            if(lastFirstTime < intervals[i][1]) ans++; // if overlapping then remove current one by not considering it's first time
            else lastFirstTime = intervals[i][0];
        }

        return ans;
        
    }
};