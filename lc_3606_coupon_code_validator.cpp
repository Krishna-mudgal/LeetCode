#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coupon-code-validator/?envType=daily-question&envId=2025-12-13

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> ans;
        vector<vector<string>> v(4);

        for(int i = 0; i < n; i++) {
            string c = code[i];
            if(c.size() == 0) continue;
            
            bool flag = false;
            for(char &x : c) {
                if(!((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x == '_')))  {
                    flag = true;
                    break;
                }
            }

            if(flag) continue;

            if(!isActive[i]) continue;
            if(businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant") continue;

            if(businessLine[i] == "electronics") v[0].push_back(c);
            else if(businessLine[i] == "grocery") v[1].push_back(c);
            else if(businessLine[i] == "pharmacy") v[2].push_back(c);
            else if(businessLine[i] == "restaurant") v[3].push_back(c);
        }

        for(auto &x : v) {
            sort(x.begin(), x.end());
            for(auto &s : x) ans.push_back(s);
        }

        return ans;
    }
};