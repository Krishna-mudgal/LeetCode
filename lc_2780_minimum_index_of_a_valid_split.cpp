#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

class Solution {
    public:
        int minimumIndex(vector<int>& nums) { // T.C. = O(n)
            int n = nums.size();
    
            unordered_map<int, int> m;
            for(auto i : nums) m[i]++;
            int x, f = -1;
            for(auto p : m){
                if(p.second > f){
                    x = p.first;
                    f = p.second;
                }
            }
    
            m.clear();
            for(int i = 0; i < n - 1; i++){
                m[nums[i]]++;
                if(m[x] > (i + 1)/2 && (f - m[x]) > (n - i - 1)/2) return i;
            }
    
            return -1;
        }
    };