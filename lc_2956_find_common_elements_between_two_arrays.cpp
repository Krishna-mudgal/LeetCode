#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-common-elements-between-two-arrays/description/

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int a1 = 0, a2 = 0;

        unordered_map<int, int> m1, m2;
        for(int e : nums1) m1[e]++;
        for(int e : nums2) m2[e]++;

        for(auto p : m1){
            if(m2.find(p.first) != m2.end()) a1 += p.second;
        }

        for(auto p : m2){
            if(m1.find(p.first) != m1.end()) a2 += p.second;
        }

        return {a1, a2};
    }
};