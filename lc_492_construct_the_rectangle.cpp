#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-the-rectangle/description/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = area, w = 1;

        vector<int> ans = {l, w};
        int p_diff = l - w;
        int x = sqrt(area);
        while(l >= w && l >= x){
            if(l*w == area){
                if(p_diff > l - w){
                    ans.clear();
                    ans.push_back(l);
                    ans.push_back(w);
                }
            }
            if(l == 1) break;
            l--;
            w = area/l;
        }

        return ans;
    }
};