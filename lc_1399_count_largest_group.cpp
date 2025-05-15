#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23

class Solution { // T.C. = O(n)
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> m;
            
            for(int i = 1; i <= n; i++){
                int x = i;
                int y = 0;
    
                while(x > 0){
                    y += x % 10;
                    x /= 10;
                }
    
                m[y]++;
            }
    
            int ans = 0, large_size = 0;
            for(auto p : m){
                if(p.second > large_size) {
                    large_size = p.second;
                    ans = 1;
                }
                else if(p.second == large_size) ans++;
            }
    
            return ans;
        }
    };