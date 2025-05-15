#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int a = 0, b = 0;
                string x , y;

                if(words[i].size() < words[j].size()){
                    x = words[i];
                    y = words[j];
                }
                else {
                    x = words[j];
                    y = words[i];
                }

                while(b < y.size()){
                    if(y[b] == x[a]){
                        int c = b;
                        while(a < x.size()){
                            if(y[c] == x[a]){
                                a++;
                                c++;
                            }
                            else break;
                        }
                        if(a == x.size()) {
                            st.insert(x);
                            break;
                        }
                        else a = 0;

                        b++;
                    }
                    else b++;
                }
            }
        }

        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};  