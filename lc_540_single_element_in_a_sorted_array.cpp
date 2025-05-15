#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // T.C = O(n

        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] != nums[i + 1]) return nums[i];
            else i++;
        }

        return nums[n - 1];
    }
};