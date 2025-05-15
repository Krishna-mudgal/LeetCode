#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int x){
    // this is already inbuilt in leet code specificly for that question
}

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        int ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(isBadVersion(mid) && !isBadVersion(mid -1)){ // mid is a bad version
                return mid;
            }
            else if(isBadVersion(mid)) hi = mid - 1;
            else lo = mid + 1;

        }

        return -1;
    }
};