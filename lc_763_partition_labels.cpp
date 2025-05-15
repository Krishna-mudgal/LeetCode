#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-labels/description/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> ans;
        unordered_map<char, int> m;

        m[s[0]] = 0;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(m.find(c) != m.end()) {
                if(ans.size() > 0 && m[c] < ans[ans.size() - 1]) {
                    while(ans.size() > 0 && ans[ans.size() - 1] > m[c]) ans.pop_back();
                }
                m[c] = i;
            }
            else {
                ans.push_back(i);
                m[c] = i;
            }
        }

        int pre_sum = 0;
        for(int i = 0; i < ans.size(); i++){
            ans[i] -= pre_sum; 
            pre_sum += ans[i];
        }   

        if(pre_sum < n) ans.push_back(n - pre_sum);

        return ans;
    }
};


class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.size();
            vector<int> ans;
            unordered_map<char, int> m;
            int i = 0, j = 0;
            while(j < n){
                m[s[j]] = j;
                j++;
            }
    
            j = 0;
            int x = 0;
            while(j < n){
                int last_index = m[s[j]];
                while(j < n && j <= last_index) {
                    last_index = max(last_index, m[s[j]]);
                    j++;
                }
                ans.push_back(j - i);
                i = j;
            }
    
            return ans;
        }
    };