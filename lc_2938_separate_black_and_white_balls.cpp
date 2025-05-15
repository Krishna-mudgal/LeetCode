#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        
        int i = 0;
        int x = 0;
        
        // hr ek 0 ke phle kitne one hai apn ko utne hi swap krne pdege us 0 ko left most laane ke liye jha ek bhi one ni h usse phle
        while(i < n){
            if(s[i] == '1') x++;
            else ans += x;

            i++;
        }

        return ans;

    }
};