#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19

class Solution {
public:
    string triangleType(vector<int>& nums) { // T.C = O(1)
        if(nums[0] + nums[1] <= nums[2]) return "none";
        if(nums[1] + nums[2] <= nums[0]) return "none";
        if(nums[0] + nums[2] <= nums[1]) return "none";

        if((nums[0] == nums[1]) && (nums[1] == nums[2])) return "equilateral";
        else if((nums[0] != nums[1]) && (nums[1] != nums[2]) && (nums[0] != nums[2])) return "scalene";
        else return "isosceles";
    }
};