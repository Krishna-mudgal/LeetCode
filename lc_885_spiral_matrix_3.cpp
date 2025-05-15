#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/spiral-matrix-iii/description/

class Solution {
    public:
        vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
            vector<vector<int>> ans;
    
            int x = 0, y = 0;
            int r_ = r;
            int c_ = c;
            while(x < rows*cols){
                y++;
                int a = c_;
                while(c_ < a + y){
                    if(r_ >= 0 && r_ < rows && c_ >= 0 && c_ < cols) {
                        ans.push_back({r_, c_});
                        x++;
                        if(x == rows*cols) break;
                    }
                    c_++;
                }
    
                if(x == rows*cols) break;
                // cout << r_ << " " << c_ << " " << y << endl;
                
                int b = r_;
                while(r_ < b + y){
                    if(r_ >= 0 && r_ < rows && c_ >= 0 && c_ < cols) {
                        ans.push_back({r_, c_});
                        x++;
                        if(x == rows*cols) break;
                    }
                    r_++;
                }
    
                if(x == rows*cols) break;
                // cout << r_ << " " << c_ << " " << y << endl;
    
                a = c_;
                y++;
                while(c_ > a - y){
                    if(r_ >= 0 && r_ < rows && c_ >= 0 && c_ < cols) {
                        ans.push_back({r_, c_});
                        x++;
                        if(x == rows*cols) break;
                    }
                    c_--;
                }
    
                if(x == rows*cols) break;
                // cout << r_ << " " << c_ << " " << y << endl;
    
                b = r_;
                while(r_ > b - y){
                    if(r_ >= 0 && r_ < rows && c_ >= 0 && c_ < cols) {
                        ans.push_back({r_, c_});
                        x++;
                        if(x == rows*cols) break;
                    }
                    r_--;
                }
                // cout << r_ << " " << c_ << " " << y << endl;
            }
    
            return ans;
        }
    };