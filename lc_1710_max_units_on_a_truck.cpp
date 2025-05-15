#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-units-on-a-truck/description/


class cmp{
public :
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first) return p1.second > p2.second;

        return p1.first > p2.first;
    }
};

class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) { // using greedy + sorting

        vector<pair<int, int>> v;

        for(int i = 0; i < boxTypes.size(); i++){
            pair<int, int> p;
            p.first = boxTypes[i][1]; // no. of units
            p.second = boxTypes[i][0]; // no. of box
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp());

        int i = 0, ans = 0;
        while(truckSize > 0 && i < v.size()){
            int units = v[i].first;
            int no = v[i].second;
            i++;

            if(no <= truckSize){
                ans += (units * no);
                truckSize -= no;
            } 
            else{
                ans += (units * truckSize); // since no > truckSize so fill according to remaining truckSize
                break;
            }
        }

        return ans;
        
    }
};