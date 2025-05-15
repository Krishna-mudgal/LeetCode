#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[0] >= rec1[2] || rec1[0] >= rec2[2]) return false; // means overlapping
        else if(rec2[1] >= rec1[3] || rec1[1] >= rec2[3]) return false; // means overlapping
        else return true;
    }   
};