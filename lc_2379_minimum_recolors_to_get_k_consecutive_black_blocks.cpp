#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
    
            int ans = INT_MAX, cnt = 0;
            for(int i = 0; i <= n - k; i++){
                cnt = 0;
                int x = 0;
                for(int j = i; j < n; j++){
                    x++;
                    if(blocks[j] == 'W') cnt++;
                    if(x == k) break;
                }
                if(x == k) ans = min(ans, cnt);
            }
    
            return ans;
        }
    };

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            // using sliding window
            int n = blocks.size();
    
            int ans = INT_MAX, i = 0, j = 0, cnt = 0;
            while(j < k){
                if(blocks[j] == 'W') cnt++;
                j++;
            }
            ans = min(ans, cnt);
    
            while(j < n){
                if(blocks[j] == 'W') cnt++;
                j++;
    
                if(blocks[i] == 'W') cnt--;
                i++;
                ans = min(ans, cnt);
            }
    
            return ans;
        }
    };