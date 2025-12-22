#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-columns-to-make-sorted/description/?envType=daily-question&envId=2025-12-20

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 0; j < n - 1; j++) {
                if(strs[j][i] > strs[j + 1][i]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};