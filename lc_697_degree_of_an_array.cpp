#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/degree-of-an-array/description/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;
        for(int i : nums) m[i]++;

        int mx_freq = 0;
        vector<int> v;
        for(auto p : m){
            if(mx_freq < p.second){
                v.clear();
                mx_freq = p.second;
                v.push_back(p.first);
            }
            else if(mx_freq == p.second){
                v.push_back(p.first);
            }
        }

        int ans = INT_MAX;
        for(int k = 0; k < v.size(); k++){
            int mx_freq_num = v[k];
            for(int i = 0; i < n; i++){
                if(nums[i] == mx_freq_num){
                    m.clear();
                    for(int j = i; j < n; j++){
                        m[nums[j]]++; 
                        if(m.find(mx_freq_num) != m.end()){
                            if(m[mx_freq_num] == mx_freq){
                                ans = min(ans, j - i + 1);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }

        return ans;

    }
};