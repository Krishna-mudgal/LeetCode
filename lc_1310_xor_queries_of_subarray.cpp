#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/1388436066/?envType=daily-question&envId=2024-09-13

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> ans;

        for(int  i = 0; i < queries.size(); i++){
            int a = queries[i][0], b = queries[i][1];

            if(a == b) ans.push_back(arr[a]);
            else{
                int x = arr[a];
                for(int i = a + 1; i <= b; i++) x = x ^ arr[i];
                ans.push_back(x);
            }
        }

        return ans;
        
    }
};

class Solution { // better approach
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {        
        int n = arr.size();
        for(int i = 1; i < n; i++) arr[i] = arr[i] ^ arr[i - 1];
        
        vector<int> ans;

        for(int i = 0; i < queries.size(); i++){
            int a = queries[i][0], b = queries[i][1];

            if(a == b){
                if(a == 0) ans.push_back(arr[a]);
                else ans.push_back(arr[a] ^ arr[a - 1]);
            }
            else if(a == 0) ans.push_back(arr[b]);
            else ans.push_back((arr[a - 1] ^ arr[b]));

        }

        return ans;
        
    }
};