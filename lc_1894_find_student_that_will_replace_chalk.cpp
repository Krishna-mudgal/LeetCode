#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();
        vector<long long> v(n);
        v[0] = chalk[0];
        for(int i = 0; i < n; i++){
            sum += chalk[i];
            if(i > 0) v[i] += chalk[i]  + v[i - 1]; // creating prefix sum
        }

        k = k % sum;

        if(k == 0) return 0;

        int lo = 0, hi = n - 1, ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(v[mid] > k){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
};