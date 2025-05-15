#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/array-nesting/description/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            v.clear();
            int idx = i, cnt = 0;
            while(true){
                if(v[idx] == 1) break;
                 
                v[idx] = 1;
                idx = nums[idx];
                cnt++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};  