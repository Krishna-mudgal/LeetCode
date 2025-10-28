#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-array-elements-equal-to-zero/description/?envType=daily-question&envId=2025-10-28

class Solution {
public:
    int countValidSelections(vector<int>& nums) { // O(n^2)
        int n = nums.size();

        int ans = 0;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                v.clear();
                for(int j : nums) {
                    v.push_back(j);
                }
                int j = i;
                char d = 'R';
                while(j >= 0 && j < n) {
                    if(v[j] > 0) {
                        v[j]--;
                        (d == 'R') ? d = 'L' : d = 'R';
                    }

                    if(d == 'R') j++;
                    else j--;
                }

                bool flag = true;
                for(int j : v) {
                    if(j > 0) {
                        flag = false;
                        break;
                    }
                }

                if(flag) ans++;

                v.clear();
                for(int j : nums) {
                    v.push_back(j);
                }
                j = i;
                d = 'L';
                while(j >= 0 && j < n) {
                    if(v[j] > 0) {
                        v[j]--;
                        (d == 'R') ? d = 'L' : d = 'R';
                    }

                    if(d == 'R') j++;
                    else j--;
                }

                flag = true;
                for(int j : v) {
                    if(j > 0) {
                        flag = false;
                        break;
                    }
                }

                if(flag) ans++;
            }
        }

        return ans;
    }
};