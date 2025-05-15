#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-array-i/description/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            if((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) return false;
        }

        return true;

    }
};

class Solution { // more optimized
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        unordered_map<string, int> m;
        
        for(int i = 0; i < n; i++){
            string x = "";
            x += s[i];
            m[x]++;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]) {
                    x += s[j];
                    m[x]++;
                }
                else break;
            }
        }

        for(auto p : m){
            if(p.second >= 3){
                int z = p.first.size();
                ans = max(ans, z);
            }
        }

        return ans;
    }
};