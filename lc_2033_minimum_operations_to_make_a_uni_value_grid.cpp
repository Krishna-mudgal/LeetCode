#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) { // T.C. = O(m*n*log(m*n))
            vector<int> v;
            int a = grid[0][0] % x;
            for(auto v2 : grid){
                for(auto y : v2){
                    if(y % x != a) return -1;
    
                    v.push_back(y);
                }
            }
    
            sort(v.begin(), v.end());
    
            bool flag = false;
            if(v.size() % 2 == 0) flag = true;
            a = 0;
            int b = 0;
    
            // we are converting each value to median value because in this - difference between all values is minimum so that will ensure we use minimum operations
            int mid1 = v[v.size()/2];
            int mid2; // we need to check two mid values in case of even size only so mid2 is needed when size of v is even
            if(flag) mid2 = v[(v.size()/2) - 1];
    
            for(int i = 0; i < v.size(); i++){
                int gap = abs(v[i] - mid1);
                a += gap/x;
    
                if(flag){
                    gap = abs(v[i] - mid2);
                    b += gap/x;
                }
            }
    
            int ans = -1;
            if(flag) ans = min(a, b);
            else ans = a;
    
            return ans;
        }
    };