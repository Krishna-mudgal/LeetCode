#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        unordered_map<int, int> m;
        
        for(int ele : nums){
            if(m.find(ele) != m.end()){
                m[ele]++;
                if(m[ele] == x) return ele;
            }
            else m[ele]++;
        }

        return -1;

    }
};