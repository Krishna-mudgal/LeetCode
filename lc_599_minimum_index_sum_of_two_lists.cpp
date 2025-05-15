#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();

        vector<string> ans;
        unordered_map<string, int> m;

        for(int i = 0; i < n1; i++) m[list1[i]] = i;

        int min_sum = INT_MAX;
        for(int i = 0; i < n2; i++){
            if(m.find(list2[i]) != m.end()){
                int a = m[list2[i]];
                int b = i;
                if(a + b == min_sum) ans.push_back(list2[i]);
                else if(a + b < min_sum){
                    ans.clear();
                    ans.push_back(list2[i]);
                    min_sum = a + b;
                }
            }
        }

        return ans;

    }
};
