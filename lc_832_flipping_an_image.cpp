#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flipping-an-image/description/

class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
            int n = image.size();
    
            int lo = 0, hi = n - 1;
    
            for(int i = 0; i < n; i++){
                lo = 0, hi = n - 1;
                while(lo <= hi){
                    swap(image[i][lo], image[i][hi]);
                    lo++;
                    hi--;
                }
            }
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(image[i][j] == 0) image[i][j] = 1;
                    else image[i][j] = 0;
                }
            }
    
            return image;
        }
    };