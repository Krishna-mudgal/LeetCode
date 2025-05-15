#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-beautiful-item-for-each-query/description/?envType=daily-question&envId=2024-11-12

class Solution {
public:

    int get_item(vector<vector<int>>& items, int &price){
        int ans = 0;
        int lo = 0, hi = items.size() - 1;

        while(lo <= hi){ // binary search se wha tk nikal lo jha tk optimum price mil rhi h
            int mid = lo + (hi - lo)/2;

            if(items[mid][0] <= price){
                ans = items[mid][1];
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        vector<int> v(queries.begin(), queries.end());

        sort(v.begin(), v.end());
        sort(items.begin(), items.end());

        int pre_max = 0;
        for(int i = 0; i < items.size(); i++){ // game changer
            pre_max = max(pre_max, items[i][1]); // ab tk jo bhi max beauty aai h usse current price ki beauty ko update krdo jisse hr ek price m max beauty uske saath hi ho
            items[i][1] = pre_max;
        }
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[v[i]] = get_item(items, v[i]);
        }   

        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(m[queries[i]]);
        }

        return ans;
    }
};