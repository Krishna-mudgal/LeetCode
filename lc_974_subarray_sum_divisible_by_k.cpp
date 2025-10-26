#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(); 

        /*
        1. To solve this question you must know the fact that if subarray is a,b,c,d,e,f  and sum of a to e is s1 and sum of a to c is s2 and s1 % k = x and s2 % k = x, then subarray s1-s2 is always divisble by k 
        proof : 
        s1 = k*n1 + x and s2 = k*n2 + x
        s1 - s2 = k*(n1 - n2);
        hence it can be clearly seen that s1 - s2 is divisible by k
        */

        int pSum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 0; i < n; i++){
            pSum += nums[i];
            int rem = pSum % k;
            if(rem < 0) rem += k;
            
            if(mp.find(rem) != mp.end()) ans += mp[rem];

            mp[rem]++;
        }

        return ans;

    }
};