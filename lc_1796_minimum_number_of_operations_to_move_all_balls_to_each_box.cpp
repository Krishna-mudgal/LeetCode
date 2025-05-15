#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06

class Solution {
public:
    vector<int> minOperations(string b) {
        int n = b.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){

            int j = 0;
            while(j < n){
                if(i == j) {
                    j++;
                    continue;
                }

                if(b[j] == '1'){
                    ans[i] += abs(j - i);
                }

                j++;
            }
        }

        return ans;
    }
};