#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/


/*

        1. i aur j me se koi sa bhi move kro to jo unke bich ka jo difference h wo 1 s km to hona hi h
        2. to ab apne pass m y direction m dekhna h jha pr apn greedy lga skte h to isme apn cahe ge ki jo bhi curr max h (height m) usko preserve krke chle apn kyu ki area nikalne me dono ka min le kar chl rhe h to ab agr to ab agr letsay ange bdi height aai to area max niklega or ab agr apn dono m jo min tha usko preserve krke rekhte to abhi jo area nikla h usse km ata,

        let say jo height[i] = 10 and height[j] = 8 or height[i + 1] = 5 and height[j + 1] = 11 to ab agr or i = 4, j = 10 to ab curr_area hoga 6*8 = 48 to ab agr m i ko move kruga to area hoga 5*5 = 25 or ab agr m j ko move kruga to area hoga 5*10 = 50 to isliye apn hmesa jo curr max h height m usko preserve krke chlege 

        */

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