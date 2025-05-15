#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) { // greedy only !!! , T.C = O(n)
        int n = height.size();

        int ans = INT_MIN;

        int i = 0, j = n - 1;

        while(i < j){
            int area = (min(height[i], height[j])) * (j - i);
            // j- i is constantly decreasing so we have to increase heights so jo bhi indo m se minimum h usko hta do

            ans = max(ans, area);

            if(height[i] > height[j]) j--; // jo bhi dono m maximum hai usko retain kro bcs agr hm jo max h usko move krdege to jb minimum nikalege to ya to purana wala min hoga ya abhi jo move krne pr aya h wo hoga to dono cases m area ghte ga hi bcs width is decreasing at every move agr purana wala min h to h area km hoga phle se aur agr dusra min h to area to bhut hi km hoga  
            else i++;
            
        }

        return ans;
    }
};