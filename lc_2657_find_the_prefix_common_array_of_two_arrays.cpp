#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> ans;
        unordered_map<int, int> m1, m2, m3, m4;

        for(int i = 0; i < n; i++){
            m1[A[i]]++;
            m2[B[i]]++;
            m3 = m1;
            m4 = m2;

            int cnt = 0;
            for(auto p : m3) {
                if(m4.find(p.first) != m4.end()) {
                    cnt += min(p.second, m4[p.first]);
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};