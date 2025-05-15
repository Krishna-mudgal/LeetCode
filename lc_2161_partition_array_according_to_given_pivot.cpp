#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03

class Solution { // T.C. = O(n), S.C. = O(n)
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            int i = 0, j = 0;
            vector<int> ans;
            vector<int> v1, v2;
            int x = 0;
            for(int i : nums){
                if(i < pivot) v1.push_back(i);
                else if(i > pivot) v2.push_back(i);
                else x++;
            }
    
            for(int i : v1) ans.push_back(i);
            for(int i = 0; i < x; i++) ans.push_back(pivot);
            for(int i : v2) ans.push_back(i);
    
            return ans;
        }
    };  