#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> >> > pq; // {val, {row, col}}

        int mx = INT_MIN; 
        for(int i = 0; i < n; i++){
            pq.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }
    
        int a = pq.top().first, b = mx; // initial wala save krke rkho
        if(a == b) return {a, b};

        while(true){
            auto p = pq.top();
            pq.pop();

            int row = p.second.first, col = p.second.second;

            if(col + 1 >= nums[row].size()) return {a, b};
            
            int nxtEleOfMin = nums[row][col + 1];
            mx = max(mx, nxtEleOfMin); // agr nxtele mx se bda h to update it

            pq.push({nxtEleOfMin, {row, col + 1}}); // nxt ele ko push krdo

            int mn = pq.top().first; // ab push krne ke baad jo min h usko nikal lo

            if(mx - mn < b - a){ // agr current scenario ki range phle jo min range save h usse bhi km h to update krdo'
                b = mx;
                a = mn;
            }
        }

        return {-1, -1};

    }
};