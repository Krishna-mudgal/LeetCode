#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) { // sorting based on first element
        int n = points.size();

        int ans = 1;
        sort(points.begin(), points.end(), cmp);

        int lastFirstElement = points[n - 1][0];

        for(int i = n - 2; i >= 0; i--){
            if(points[i][1] < lastFirstElement){ // if it is not overlapping with ballon after this than add it in ans and next time compare with it's first time to check if ballon before this is overlapping eith this one or not if yes then we don't ned to count that ballon
                ans++;
                lastFirstElement = points[i][0];
            }
        }

        return ans;

    }
};

// variation -2 

bool cmp(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) { // sorting based on zero element
        int n = points.size();

        int ans = 1;
        sort(points.begin(), points.end(), cmp);

        int lastEndElement = points[0][1];

        for(int i = 1; i < n; i++){
            if(lastEndElement < points[i][0]){ // if it is not overlapping with ballon before this than add it in ans and next time compare with it's end time to check if ballon before this is overlapping with this one or not if yes then we don't ned to count that ballon
                ans++;
                lastEndElement = points[i][1];
            }
        }

        return ans;

    }
};  

// approach - 2

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) { // approach 2 - in this i have sorted points with zero idx element, similarly, we can also go with first idx sorting but logic will change
        // approach -> ans = total intervals - overlapping interavals
        int n = points.size();
        sort(points.begin(), points.end(), cmp); 

        int lastFirstElement = points[n - 1][0];
        int overLappingIntervals = 0;

        for(int i = n - 2 ; i >= 0; i--){
            if(points[i][1] >= lastFirstElement) overLappingIntervals++; // overlapping exists
            else lastFirstElement = points[i][0];
        }

        return points.size() - overLappingIntervals;
        
    }
};