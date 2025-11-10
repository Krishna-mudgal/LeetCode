#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10

class Solution {
public:
    int minOperations(vector<int>& nums) { // T.C. = O(n)
        int n = nums.size();

        int ans = 0;
        stack<int> st;
        for(auto i : nums) {
            
            if(i == 0) {
                st = stack<int>();
                continue;
            }

            if(st.size() == 0 || st.top() < i) {
                st.push(i);
                ans++;
            } else if(st.top() > i) {
                while(!st.empty() && st.top() > i) st.pop();
                if(!st.empty() && st.top() == i) continue;
                st.push(i);
                ans++;
            }
        }

        return ans;
    }
};