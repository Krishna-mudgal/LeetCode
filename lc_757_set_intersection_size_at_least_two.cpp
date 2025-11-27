#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-intersection-size-at-least-two/description/?envType=daily-question&envId=2025-11-20

bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[1] < v2[1]; 
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp); // interval ke end ke basis per sort krlo

        int i = 1;
        ans += 2;
        int b = intervals[0][1];
        int a = b - 1;
        while(i < n) {
            if(intervals[i][0] > b) { // agr a or b dono range se chote h
                ans += 2;
                b = intervals[i][1];
                a = b - 1;
            } else if(intervals[i][0] == b){ // agr b equal h range ke start ke
                a = b;
                b = intervals[i][1];
                ans++;
            } else if(intervals[i][0] < b) {
                if(intervals[i][1] > b) { // agr b range ke andr h
                    if(intervals[i][0] > a) { // ab agr a range ke andar ni h
                        a = b;
                        b = intervals[i][1];
                        ans++;
                    } // else means a bhi range ke andr h to kch krne ki jrurt ni h kyu ki a or b dono range m h
                }
                else if(b == intervals[i][1]) { // agr b range jha end ho rhi h uske equal h to
                    if(intervals[i][0] > a) { // agr a range se bhar h to
                        a = b - 1;
                        ans++;
                    } 
                }
            }

            i++;
        }

        return ans;
    }
};