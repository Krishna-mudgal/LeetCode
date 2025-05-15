#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // jo jitna jada gain dega ek student ke badne se usko class ko choose kro to pq m hr class ka gain daalo kon jada dega

        int n = classes.size();

        priority_queue<pair<double, pair<int, int>>> pq;
        
        for(auto v : classes){
            int pass = v[0], total = v[1];
            double gain = (pass/(double)total) - ((pass + 1)/(double)(total + 1));
            pq.push({-gain, {pass, total}});
        }

        while(extraStudents > 0){
            auto p = pq.top();
            pq.pop();

            int pass = p.second.first, total = p.second.second;
            pass++;
            total++;
            extraStudents--;
            double gain = (pass/(double)total) - ((pass + 1)/(double)(total + 1));
            pq.push({-gain, {pass, total}});
        }

        double ans = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            ans += p.second.first/(double)p.second.second;
        }

        return ans/classes.size();
    }
};