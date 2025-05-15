#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/alternating-groups-i/description/

class Solution { // T.C. = O(n)
    public:
        int numberOfAlternatingGroups(vector<int>& colors) {
            // solving by extending array
            // if we are at last position then we need to next check first 2 tiles so we are extending first two tiles
    
            colors.push_back(colors[0]);
            colors.push_back(colors[1]);
    
            int n = colors.size();
            int ans = 0;
            int i = 0, j = 0;
    
            while(j < n){
                if(j + 1 < n && colors[j] != colors[j + 1]) j++;
                else {
                    j++;
                    while(j - i >= 3) {
                        ans++;
                        i++;
                    }
                    i = j;
                }
            }
    
            return ans;
        }
    };