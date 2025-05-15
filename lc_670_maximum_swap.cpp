#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ans = num;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '9') continue;

            int idx = i; 
            // s[i] se sbse bda element nikal lo right side m
            for(int j = i + 1; j < n; j++){
                if(s[j] >= s[idx]) idx = j;
            }

            swap(s[i], s[idx]);
            int x = stoi(s);
            ans = max(ans, x);
            swap(s[i], s[idx]);
        }
        
        return ans;
    }
};