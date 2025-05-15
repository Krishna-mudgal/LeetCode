#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17

class Solution { // T.C. = O(n)
    public:
        bool divideArray(vector<int>& nums) {
            vector<int> v(501, 0);
    
            for(int i = 0; i < nums.size(); i++){
                v[nums[i]]++;
            }
    
            for(int i = 0; i < 501; i++){
                if(v[i] % 2 != 0) return false;
            }
    
            return true;
        }
    };