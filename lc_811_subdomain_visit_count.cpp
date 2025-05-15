#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subdomain-visit-count/description/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();

        unordered_map<string, int> m;

        for(int i = 0; i < n; i++){
            string s = cpdomains[i];

            int j = 0;
            string freq = "";
            while(j < s.size()){
                if(isdigit(s[j])) {
                    freq += s[j];
                    j++;
                }
                else if(s[j] == ' ') j++;
                else{
                    string y = s.substr(j);
                    m[y] += stoi(freq);

                    while(j < s.size() && s[j] != '.') j++;
                    j++;
                }
            }
        }
        
        vector<string> ans;
        for(auto p : m){
            int freq = p.second;
            string s = p.first;
            
            ans.push_back(to_string(freq) + " " + s);
        }

        return ans;
    }
};