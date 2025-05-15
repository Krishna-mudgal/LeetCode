#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-lines-to-write-string/description/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();

        int pixel_cnt = 0, total_lines = 0;
        for(int i = 0; i < n; i++){
            char c = s[i];

            if(pixel_cnt + widths[c - 'a'] <= 100) pixel_cnt += widths[c - 'a'];
            else {
                total_lines++;
                pixel_cnt = 0;
                pixel_cnt += widths[c - 'a'];
            }
        }
        total_lines++;
        
        return {total_lines, pixel_cnt};
    }
};