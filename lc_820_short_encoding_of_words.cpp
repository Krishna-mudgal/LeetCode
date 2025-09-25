#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/short-encoding-of-words/description/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) { // O(n) + O(n*(log(n))) + O(n^2) == O(n^2)
        int n = words.size();

        string s = "";
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({words[i].size(), i}); // O(n)
        sort(v.begin(), v.end()); // O(n*(log(n)))

        unordered_set<string> st;
        for(int k = n - 1; k >= 0; k--) { // O(n)
            string x = words[v[k].second];
            // cout << s << " " << x << endl;
            if(st.find(x) == st.end()) {
                int i = x.size() - 1;
                int j = s.size() - 1;
                bool flag = true;
                while(j >= 0) { // O(7*n)
                    while(j >= 0 && s[j] == '#') j--;
                    if(s[j] == x[i]) {
                        while(j >= 0 && i >= 0 && s[j] == x[i]) {
                            i--;
                            j--;
                        }

                        if(i == -1) {
                            flag = false;
                            break;
                        }

                        i = x.size() - 1;
                    }
                    while(j >= 0 && s[j] != '#') j--;
                }

                if(flag) {
                    s += x;
                    s += "#";
                }
            }

            st.insert(x);
        }

        return s.size();
    }
};